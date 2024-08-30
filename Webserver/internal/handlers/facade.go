package handlers

import (
	"context"

	pb "github.com/SudarshanZone/Open_Pos/generated"
	ob "github.com/SudarshanZone/Ord_Dtls/generated"
	"github.com/SudarshanZone/Web_Server/internal/grpc"
)

// type Facade interface {
// 	GetFNOPosition(account string) (*pb.FcpDetail, error)
// 	GetOrderDetails(orderID string) (*ob.OrderDetailsResponse, error)
// }

type Facade interface {
	GetFNOPosition(account string) (*pb.FcpDetailListResponse, error)
	GetOrderDetails(orderID string) (*ob.OrderDetailsResponse, error)
}

func (f *facade) GetFNOPosition(account string) (*pb.FcpDetailListResponse, error) {
	return f.adapter.GetFNOPosition(context.Background(), account)
}


type facade struct {
	adapter grpc.Adapter
}

func NewFacade(adapter grpc.Adapter) Facade {
	return &facade{adapter: adapter}
}

// func (f *facade) GetFNOPosition(account string) (*pb.FcpDetail, error) {
// 	return f.adapter.GetFNOPosition(context.Background(), account)
// }

func (f *facade) GetOrderDetails(orderID string) (*ob.OrderDetailsResponse, error) {
	return f.adapter.GetOrderDetails(context.Background(), orderID)
}
