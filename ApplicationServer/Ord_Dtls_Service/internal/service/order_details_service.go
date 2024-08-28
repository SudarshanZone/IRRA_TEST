package service

import (
	"context"
	"fmt"
	pb "github.com/SudarshanZone/Ord_Dtls/generated"
	"github.com/SudarshanZone/Ord_Dtls/internal/repository"
)

type OrderDetailsService struct {
	Repo repository.OrderDetailsRepository
	pb.UnimplementedOrderDetailsServiceServer
}

func (s *OrderDetailsService) GetOrderDetails(ctx context.Context, req *pb.OrderDetailsRequest) (*pb.OrderDetailsResponse, error) {
	orderDetails, err := s.Repo.GetOrderDetailsByClaimMatchAccount(req.FOD_CLM_MTCH_ACCNT)
	if err != nil {
		return nil, fmt.Errorf("failed to get order details: %w", err)
	}

	response := &pb.OrderDetailsResponse{}
	for _, detail := range orderDetails {
		response.ContractDescriptor = append(response.ContractDescriptor, detail.ContractDescriptor)
		response.VTCDate = append(response.VTCDate, detail.VTCDate)
		response.BuySell = append(response.BuySell, detail.BuySell)
		response.Quantity = append(response.Quantity, detail.Quantity)
		response.Status = append(response.Status, detail.Status)
		response.OrderPrice = append(response.OrderPrice, detail.OrderPrice)
		response.Open = append(response.Open, detail.Open)
	}

	return response, nil
}
