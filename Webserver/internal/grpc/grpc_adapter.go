<<<<<<< HEAD
=======
//Webserver\internal\grpc\grpc_adapter.go
>>>>>>> master
package grpc

import (
	"context"
<<<<<<< HEAD
	pb "github.com/SudarshanZone/Open_Pos/generated"
    ob "github.com/SudarshanZone/Ord_Dtls/generated"
)

type Adapter interface {
	GetFNOPosition(ctx context.Context, account string) (*pb.FnoPositionResponse, error)
=======
	"fmt"

	pb "github.com/SudarshanZone/Open_Pos/generated"
	ob "github.com/SudarshanZone/Ord_Dtls/generated"
)

type Adapter interface {
	GetFNOPosition(ctx context.Context, account string) (*pb.FcpDetailListResponse, error)
>>>>>>> master
	GetOrderDetails(ctx context.Context, orderID string) (*ob.OrderDetailsResponse, error)
}

type grpcAdapter struct {
	fnoClient pb.FnoPositionServiceClient
	orderClient ob.OrderDetailsServiceClient
}

func NewGrpcAdapter(fnoClient pb.FnoPositionServiceClient, orderClient ob.OrderDetailsServiceClient) Adapter {
	return &grpcAdapter{
		fnoClient: fnoClient,
		orderClient: orderClient,
	}
}

<<<<<<< HEAD
func (a *grpcAdapter) GetFNOPosition(ctx context.Context, account string) (*pb.FnoPositionResponse, error) {
	req := &pb.FnoPositionRequest{
		FCP_CLM_MTCH_ACCNT: account,
	}
	return a.fnoClient.GetFNOPosition(ctx, req)
}

=======

func (a *grpcAdapter) GetFNOPosition(ctx context.Context, account string) (*pb.FcpDetailListResponse, error) {
	req := &pb.FnoPositionRequest{
		FCP_CLM_MTCH_ACCNT: account,
	}
	
	// Call the gRPC service
	resp, err := a.fnoClient.GetFNOPosition(ctx, req)
	if err != nil {
		return nil, fmt.Errorf("failed to fetch FNO positions: %w", err)
	}

	// Return the entire response
	return resp, nil
}


>>>>>>> master
func (a *grpcAdapter) GetOrderDetails(ctx context.Context, orderID string) (*ob.OrderDetailsResponse, error) {
	req := &ob.OrderDetailsRequest{
		FOD_CLM_MTCH_ACCNT: orderID,
	}
	return a.orderClient.GetOrderDetails(ctx, req)
}