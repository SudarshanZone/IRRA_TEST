// Webserver\internal\config\config.go
package config

import (
	"github.com/go-ini/ini"
)

type Config struct {
	ServerAddress      string
	GRPCServerAddress1 string
	GRPCServerAddress2 string
}

func LoadConfig(fileName string) (*Config, error) {
	cfg, err := ini.Load(fileName)
	if err != nil {
		return nil, err
	}

	return &Config{
		ServerAddress:      cfg.Section("").Key("server_address").MustString(":8080"),
		GRPCServerAddress1: cfg.Section("").Key("grpc_server_address_1").MustString("localhost:50051"),
		GRPCServerAddress2: cfg.Section("").Key("grpc_server_address_2").MustString("localhost:50052"),
	}, nil
}


// package config

// import (
// 	"github.com/go-ini/ini"
// )

// type Config struct {
// 	ServerAddress    string
// 	GRPCServerAddress string
// }

// func LoadConfig(fileName string) (*Config, error) {
// 	cfg, err := ini.Load(fileName)
// 	if err != nil {
// 		return nil, err
// 	}

// 	return &Config{
// 		ServerAddress:    cfg.Section("").Key("server_address").MustString(":8080"),
// 		GRPCServerAddress: cfg.Section("").Key("grpc_server_address").MustString("localhost:50051"),
		
// 	}, nil
// }

