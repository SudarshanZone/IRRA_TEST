<<<<<<< HEAD
=======
//Webserver\internal\grpc\client.go
>>>>>>> master
package grpc

import (
	"log"
	"google.golang.org/grpc"
	pb "github.com/SudarshanZone/Open_Pos/generated"
    ob "github.com/SudarshanZone/Ord_Dtls/generated"
    
)

type Client struct {
<<<<<<< HEAD
	conn                           *grpc.ClientConn
=======
	conn1                         *grpc.ClientConn
	conn2                         *grpc.ClientConn
>>>>>>> master
	FnoPositionServiceClient       pb.FnoPositionServiceClient
	OrderDetailsServiceClient      ob.OrderDetailsServiceClient
}

<<<<<<< HEAD
func NewClient(address string) (Client, error) {
	conn, err := grpc.Dial(address, grpc.WithInsecure())
=======
func NewClient(address1, address2 string) (Client, error) {
	// Connect to the first gRPC server
	conn1, err := grpc.Dial(address1, grpc.WithInsecure())
	if err != nil {
		return Client{}, err
	}

	// Connect to the second gRPC server
	conn2, err := grpc.Dial(address2, grpc.WithInsecure())
>>>>>>> master
	if err != nil {
		return Client{}, err
	}

	return Client{
<<<<<<< HEAD
		conn:                           conn,
		FnoPositionServiceClient:       pb.NewFnoPositionServiceClient(conn),
		OrderDetailsServiceClient:      ob.NewOrderDetailsServiceClient(conn),
=======
		conn1:                        conn1,
		conn2:                        conn2,
		FnoPositionServiceClient:     pb.NewFnoPositionServiceClient(conn1),
		OrderDetailsServiceClient:    ob.NewOrderDetailsServiceClient(conn2),
>>>>>>> master
	}, nil
}

func (c *Client) Close() {
<<<<<<< HEAD
	if err := c.conn.Close(); err != nil {
		log.Printf("Failed to close gRPC connection: %v", err)
=======
	if err := c.conn1.Close(); err != nil {
		log.Printf("Failed to close gRPC connection 1: %v", err)
	}
	if err := c.conn2.Close(); err != nil {
		log.Printf("Failed to close gRPC connection 2: %v", err)
>>>>>>> master
	}
}
