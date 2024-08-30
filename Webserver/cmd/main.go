package main

import (
	"fmt"
	"os"
	"time"
	"github.com/gin-contrib/cors"
	"github.com/gin-gonic/gin"
	"github.com/sirupsen/logrus"
	"github.com/SudarshanZone/Web_Server/internal/config"
	"github.com/SudarshanZone/Web_Server/internal/grpc"
	"github.com/SudarshanZone/Web_Server/internal/handlers"
	"github.com/SudarshanZone/Web_Server/internal/utils"
)

func init() {
<<<<<<< HEAD
	// Set Gin to release mode for production
	gin.SetMode(gin.ReleaseMode)
	
	// Initialize custom logger
=======
	gin.SetMode(gin.ReleaseMode)
	
>>>>>>> master
	utils.Logger.SetFormatter(&logrus.JSONFormatter{})
	utils.Logger.SetOutput(os.Stdout)
	utils.Logger.SetLevel(logrus.InfoLevel)
}

func main() {
	logger := utils.Logger.WithFields(logrus.Fields{
		"component": "webserver",
	})

<<<<<<< HEAD
	// Load configuration
=======
	// Load config
>>>>>>> master
	cfg, err := config.LoadConfig("internal/config/EnvConfig.ini")
	if err != nil {
		logger.Fatalf("Failed to load config: %v", err)
	}

	// Create gRPC client
<<<<<<< HEAD
	grpcClient, err := grpc.NewClient(cfg.GRPCServerAddress)
=======
	grpcClient, err := grpc.NewClient(cfg.GRPCServerAddress1, cfg.GRPCServerAddress2)
>>>>>>> master
	if err != nil {
		logger.Fatalf("Failed to create gRPC client: %v", err)
	}
	defer grpcClient.Close()

<<<<<<< HEAD
	// Initialize gRPC adapter with both service clients
=======
	// Initialize gRPC adapters for Clients
>>>>>>> master
	grpcAdapter := grpc.NewGrpcAdapter(
		grpcClient.FnoPositionServiceClient,
		grpcClient.OrderDetailsServiceClient,
	)

<<<<<<< HEAD
	// Create facade with the updated adapter
	facade := handlers.NewFacade(grpcAdapter)
	router := gin.New() // Create a new Engine instance

	// Attach default Logger and Recovery middleware
=======
	// Create facade 
	facade := handlers.NewFacade(grpcAdapter)
	router := gin.New() 

	
>>>>>>> master
	router.Use(gin.LoggerWithFormatter(func(param gin.LogFormatterParams) string {
		return fmt.Sprintf(
			`{"time":"%s","method":"%s","path":"%s","status":%d,"latency":%s,"client_ip":"%s"}` + "\n",
			param.TimeStamp.Format(time.RFC3339),
			param.Method,
			param.Path,
			param.StatusCode,
			param.Latency,
			param.ClientIP,
		)
	}))
	router.Use(gin.Recovery())

	// CORS configuration
	router.Use(cors.New(cors.Config{
<<<<<<< HEAD
		AllowOrigins:     []string{"https://example.com"}, // Restrict to trusted domains
=======
		AllowOrigins:     []string{"*"}, 
>>>>>>> master
		AllowMethods:     []string{"GET", "POST", "PUT", "DELETE", "OPTIONS"},
		AllowHeaders:     []string{"Origin", "Content-Type", "Authorization"},
		AllowCredentials: true,
	}))

<<<<<<< HEAD
	// Set trusted proxies (if applicable)
	router.SetTrustedProxies([]string{"127.0.0.1"}) // Update with actual trusted proxies if needed

	// Security headers
=======
	// Setup For Proxy
	//router.SetTrustedProxies([]string{"127.0.0.1"}) 


>>>>>>> master
	router.Use(func(c *gin.Context) {
		c.Writer.Header().Set("X-Frame-Options", "DENY")
		c.Writer.Header().Set("X-XSS-Protection", "1; mode=block")
		c.Next()
	})

	// Setup routes
	handlers.SetupRoutes(router, facade, logger)

<<<<<<< HEAD
	// Start the web server
=======
	// Start the web server 8080
>>>>>>> master
	logger.Info("Starting web server on ", cfg.ServerAddress)
	if err := router.Run(cfg.ServerAddress); err != nil {
		logger.Fatalf("Failed to start server: %v", err)
	}
}

<<<<<<< HEAD

// package main

// import (
// 	"os"
// 	"github.com/gin-contrib/cors"
// 	"github.com/gin-gonic/gin"
// 	"github.com/sirupsen/logrus"
// 	"github.com/SudarshanZone/Web_Server/internal/config"
// 	"github.com/SudarshanZone/Web_Server/internal/grpc"
// 	"github.com/SudarshanZone/Web_Server/internal/handlers"
// 	"github.com/SudarshanZone/Web_Server/internal/utils" 
// )

// func init() {
// 	// Set Gin to release mode for production
// 	gin.SetMode(gin.ReleaseMode)
	
// 	// Initialize custom logger
// 	utils.Logger.SetFormatter(&logrus.JSONFormatter{})
// 	utils.Logger.SetOutput(os.Stdout)
// 	utils.Logger.SetLevel(logrus.InfoLevel)
// }

// func main() {
// 	logger := utils.Logger.WithFields(logrus.Fields{
// 		"component": "webserver",
// 	})

// 	// Load configuration
// 	cfg, err := config.LoadConfig("internal/config/EnvConfig.ini")
// 	if err != nil {
// 		logger.Fatalf("Failed to load config: %v", err)
// 	}

// 	// Create gRPC client
// 	grpcClient, err := grpc.NewClient(cfg.GRPCServerAddress)
// 	if err != nil {
// 		logger.Fatalf("Failed to create gRPC client: %v", err)
// 	}
// 	defer grpcClient.Close()

// 	// Initialize gRPC adapter with both service clients
// 	grpcAdapter := grpc.NewGrpcAdapter(
// 		grpcClient.FnoPositionServiceClient,
// 		grpcClient.OrderDetailsServiceClient,
// 	)

// 	// Create facade with the updated adapter
// 	facade := handlers.NewFacade(grpcAdapter)
// 	router := gin.New() // Create a new Engine instance

// 	// Attach default Logger and Recovery middleware
// 	router.Use(gin.Logger())
// 	router.Use(gin.Recovery())

// 	// CORS configuration
// 	router.Use(cors.New(cors.Config{
// 		AllowOrigins:     []string{"*"},
// 		AllowMethods:     []string{"GET", "POST", "PUT", "DELETE", "OPTIONS"},
// 		AllowHeaders:     []string{"Origin", "Content-Type", "Authorization"},
// 		AllowCredentials: true,
// 	}))

// 	// Set trusted proxies (if applicable)
// 	router.SetTrustedProxies([]string{"127.0.0.1"}) // Update with actual trusted proxies if needed

// 	// Setup routes
// 	handlers.SetupRoutes(router, facade, logger)

// 	// Start the web server
// 	logger.Info("Starting web server on ", cfg.ServerAddress)
// 	if err := router.Run(cfg.ServerAddress); err != nil {
// 		logger.Fatalf("Failed to start server: %v", err)
// 	}
// }






=======
>>>>>>> master
