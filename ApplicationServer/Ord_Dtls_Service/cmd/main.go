package main

import (
	"log"
	"net"
<<<<<<< HEAD
	"github.com/SudarshanZone/Ord_Dtls/config"
	pb "github.com/SudarshanZone/Ord_Dtls/generated"
	"github.com/SudarshanZone/Ord_Dtls/internal/service"
	"github.com/SudarshanZone/Ord_Dtls/internal/repository"
=======

	"github.com/SudarshanZone/Ord_Dtls/config"
	pb "github.com/SudarshanZone/Ord_Dtls/generated"
	"github.com/SudarshanZone/Ord_Dtls/internal/repository"
	"github.com/SudarshanZone/Ord_Dtls/internal/service"
>>>>>>> master
	"google.golang.org/grpc"
)

func main() {
	serviceName := "main"
	fileName := "config/EnvConfig.ini"

	cm := &config.ConfigManager{}

<<<<<<< HEAD
	// Load PostgreSQL config
=======
	// Load PostgreSQL configuration
>>>>>>> master
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

<<<<<<< HEAD
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
=======
	// Initialize the repository with the database connection
	repo := repository.OrderDetailsRepository{Db: db}

	// Initialize the service with the repository
	orderDetailsService := &service.OrderDetailsService{Repo: repo}

	// Set up gRPC server
	grpcServer := grpc.NewServer()
	pb.RegisterOrderDetailsServiceServer(grpcServer, orderDetailsService)

	// Listen on a TCP port
	listener, err := net.Listen("tcp", ":50052")
>>>>>>> master
	if err != nil {
		log.Fatalf("Failed to listen on port 50052: %v", err)
	}

<<<<<<< HEAD
	grpcOrderServer := grpc.NewServer()
	pb.RegisterOrderDetailsServiceServer(grpcOrderServer, orderSrv)

	log.Println("Starting gRPC server for Order Details Service on port 50052")
	if err := grpcOrderServer.Serve(orderLis); err != nil {
		log.Fatalf("Failed to serve Order Details Service gRPC server: %v", err)
=======
	// Start the gRPC server
	log.Println("Starting gRPC server on port 50052...")
	if err := grpcServer.Serve(listener); err != nil {
		log.Fatalf("Failed to serve gRPC server: %v", err)
>>>>>>> master
	}
}
