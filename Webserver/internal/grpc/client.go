package grpc

import (
	"log"
	"google.golang.org/grpc"
	pb "github.com/SudarshanZone/Open_Pos/generated"
    ob "github.com/SudarshanZone/Ord_Dtls/generated"
    
)

type Client struct {
	conn                           *grpc.ClientConn
	FnoPositionServiceClient       pb.FnoPositionServiceClient
	OrderDetailsServiceClient      ob.OrderDetailsServiceClient
}

func NewClient(address string) (Client, error) {
	conn, err := grpc.Dial(address, grpc.WithInsecure())
	if err != nil {
		return Client{}, err
	}

	return Client{
		conn:                           conn,
		FnoPositionServiceClient:       pb.NewFnoPositionServiceClient(conn),
		OrderDetailsServiceClient:      ob.NewOrderDetailsServiceClient(conn),
	}, nil
}

func (c *Client) Close() {
	if err := c.conn.Close(); err != nil {
		log.Printf("Failed to close gRPC connection: %v", err)
	}
}
