//ApplicationServer\Open_Pos\cmd\main.go
package main

import (
	"log"
	"net"

	"github.com/SudarshanZone/Open_Pos/config"
	positions "github.com/SudarshanZone/Open_Pos/generated"
	"github.com/SudarshanZone/Open_Pos/internal/service"
	"github.com/SudarshanZone/Open_Pos/internal/repository"
	"google.golang.org/grpc"
)

func main() {
	serviceName := "main"
	fileName := "config/EnvConfig.ini"

	cm := &config.ConfigManager{}

	dbConfig, err := cm.LoadPostgreSQLConfig(serviceName, fileName)
	if err != nil {
		log.Fatalf("Failed to load database config: %v", err)
	}

	connectionStatus := cm.GetDatabaseConnection(serviceName, *dbConfig)
	if connectionStatus != 0 {
		log.Fatalf("Failed to connect to the database")
	}

	db := cm.GetDB(serviceName)

	repo := &repository.FnoPositionRepository{Db: db}
	srv := &service.FnoPositionService{Repo: *repo}

	lis, err := net.Listen("tcp", ":50051")
	if err != nil {
		log.Fatalf("Failed to listen on port 50051: %v", err)
	}

	grpcServer := grpc.NewServer()
	positions.RegisterFnoPositionServiceServer(grpcServer, srv)

	log.Println("Starting gRPC server on port 50051")
	if err := grpcServer.Serve(lis); err != nil {
		log.Fatalf("Failed to serve gRPC server: %v", err)
	}
}
// package main

// import (
// 	"log"
// 	"net"

// 	"github.com/SudarshanZone/Open_Pos/config"
// 	positions "github.com/SudarshanZone/Open_Pos/generated"
// 	"github.com/SudarshanZone/Open_Pos/internal/service"
// 	"google.golang.org/grpc"
// )

// func main() {
// 	serviceName := "main"
// 	fileName := "config/EnvConfig.ini"

// 	cm := &config.ConfigManager{}

// 	dbConfig, err := cm.LoadPostgreSQLConfig(serviceName, fileName)
// 	if err != nil {
// 		log.Fatalf("Failed to load database config: %v", err)
// 	}

// 	connectionStatus := cm.GetDatabaseConnection(serviceName, *dbConfig)
// 	if connectionStatus != 0 {
// 		log.Fatalf("Failed to connect to the database")
// 	}

// 	db := cm.GetDB(serviceName)
	
// 	server := &service.Server{
// 		Db: db,
// 	}

// 	lis, err := net.Listen("tcp", ":50051")
// 	if err != nil {
// 		log.Fatalf("Failed to listen on port 50051: %v", err)
// 	}

// 	grpcServer := grpc.NewServer()
// 	positions.RegisterFnoPositionServiceServer(grpcServer, server)

// 	log.Println("Starting gRPC server on port 50051")
// 	if err := grpcServer.Serve(lis); err != nil {
// 		log.Fatalf("Failed to serve gRPC server: %v", err)
// 	}
// }
