//Webserver\internal\grpc\client.go
package grpc

import (
	"log"
	"google.golang.org/grpc"
	pb "github.com/SudarshanZone/Open_Pos/generated"
    ob "github.com/SudarshanZone/Ord_Dtls/generated"
    
)

type Client struct {
	conn1                         *grpc.ClientConn
	conn2                         *grpc.ClientConn
	FnoPositionServiceClient       pb.FnoPositionServiceClient
	OrderDetailsServiceClient      ob.OrderDetailsServiceClient
}

func NewClient(address1, address2 string) (Client, error) {
	// Connect to the first gRPC server
	conn1, err := grpc.Dial(address1, grpc.WithInsecure())
	if err != nil {
		return Client{}, err
	}

	// Connect to the second gRPC server
	conn2, err := grpc.Dial(address2, grpc.WithInsecure())
	if err != nil {
		return Client{}, err
	}

	return Client{
		conn1:                        conn1,
		conn2:                        conn2,
		FnoPositionServiceClient:     pb.NewFnoPositionServiceClient(conn1),
		OrderDetailsServiceClient:    ob.NewOrderDetailsServiceClient(conn2),
	}, nil
}

func (c *Client) Close() {
	if err := c.conn1.Close(); err != nil {
		log.Printf("Failed to close gRPC connection 1: %v", err)
	}
	if err := c.conn2.Close(); err != nil {
		log.Printf("Failed to close gRPC connection 2: %v", err)
	}
}
