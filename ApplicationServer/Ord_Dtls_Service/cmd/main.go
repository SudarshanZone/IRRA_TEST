package main

import (
	"log"
	"net"
	"github.com/SudarshanZone/Ord_Dtls/config"
	pb "github.com/SudarshanZone/Ord_Dtls/generated"
	"github.com/SudarshanZone/Ord_Dtls/internal/service"
	"github.com/SudarshanZone/Ord_Dtls/internal/repository"
	"google.golang.org/grpc"
)

func main() {
	serviceName := "main"
	fileName := "config/EnvConfig.ini"

	cm := &config.ConfigManager{}

	// Load PostgreSQL config
	dbConfig, err := cm.LoadPostgreSQLConfig(serviceName, fileName)
	if err != nil {
		log.Fatalf("Failed to load database config: %v", err)
	}

	// Get database connection
	connectionStatus := cm.GetDatabaseConnection(serviceName, *dbConfig)
	if connectionStatus != 0 {
		log.Fatalf("Failed to connect to the database")
	}

	db := cm.GetDB(serviceName)

	// Setup FNO Position Service
	fnoRepo := &repository.OrderDetailsRepository{Db: db}
	fnoSrv := &service.OrderDetailsService{Repo: *fnoRepo}

	// Setup Order Details Service
	orderRepo := &repository.OrderDetailsRepository{Db: db}
	orderSrv := &service.OrderDetailsService{Repo: *orderRepo}

	// FNO Position Service
	fnoLis, err := net.Listen("tcp", ":50051")
	if err != nil {
		log.Fatalf("Failed to listen on port 50051: %v", err)
	}

	grpcFnoServer := grpc.NewServer()
	pb.RegisterOrderDetailsServiceServer(grpcFnoServer, fnoSrv)

	log.Println("Starting gRPC server for FNO Position Service on port 50051")
	go func() {
		if err := grpcFnoServer.Serve(fnoLis); err != nil {
			log.Fatalf("Failed to serve FNO Position Service gRPC server: %v", err)
		}
	}()

	// Order Details Service
	orderLis, err := net.Listen("tcp", ":50052")
	if err != nil {
		log.Fatalf("Failed to listen on port 50052: %v", err)
	}

	grpcOrderServer := grpc.NewServer()
	pb.RegisterOrderDetailsServiceServer(grpcOrderServer, orderSrv)

	log.Println("Starting gRPC server for Order Details Service on port 50052")
	if err := grpcOrderServer.Serve(orderLis); err != nil {
		log.Fatalf("Failed to serve Order Details Service gRPC server: %v", err)
	}
}
