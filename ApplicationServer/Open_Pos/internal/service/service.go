package service

import (
	"context"
	"fmt"
<<<<<<< HEAD
	pb "github.com/SudarshanZone/Open_Pos/generated"
=======
	pb"github.com/SudarshanZone/Open_Pos/generated"
>>>>>>> master
	"github.com/SudarshanZone/Open_Pos/internal/repository"
)

type FnoPositionService struct {
	Repo repository.FnoPositionRepository
	pb.UnimplementedFnoPositionServiceServer
}

<<<<<<< HEAD
func (s *FnoPositionService) GetFNOPosition(ctx context.Context, req *pb.FnoPositionRequest) (*pb.FnoPositionResponse, error) {
=======
func (s *FnoPositionService) GetFNOPosition(ctx context.Context, req *pb.FnoPositionRequest) (*pb.FcpDetailListResponse, error) {
>>>>>>> master
	positions, err := s.Repo.GetPositionsByClaimMatchAccount(req.FCP_CLM_MTCH_ACCNT)
	if err != nil {
		return nil, fmt.Errorf("failed to get positions: %w", err)
	}

<<<<<<< HEAD
	response := &pb.FnoPositionResponse{}
	for _, pos := range positions {
		response.FFO_CONTRACT = append(response.FFO_CONTRACT, pos.Contract)
		response.FFO_PSTN = append(response.FFO_PSTN, pos.Position)
		response.FFO_QTY = append(response.FFO_QTY, int32(pos.TotalQty))
		response.FFO_AVG_PRC = append(response.FFO_AVG_PRC, float32(pos.AvgCostPrice))
		response.FCP_XCHNG_CD = append(response.FCP_XCHNG_CD, pos.ExchangeCode)
		response.FCP_IBUY_QTY = append(response.FCP_IBUY_QTY, int32(pos.BuyQty))
		response.FCP_CLM_MTCH_ACCNT = pos.ClaimMatchAccount
		response.FCP_PRDCT_TYP = append(response.FCP_PRDCT_TYP, pos.ProductType)
		response.FCP_INDSTK = append(response.FCP_INDSTK, pos.IndexStock)
		response.FCP_UNDRLYNG = append(response.FCP_UNDRLYNG, pos.Underlying)
		response.FCP_EXPRY_DT = append(response.FCP_EXPRY_DT, pos.ExpiryDate)
		response.FCP_EXER_TYP = append(response.FCP_EXER_TYP, pos.ExerciseType)
		response.FCP_OPT_TYP = append(response.FCP_OPT_TYP, pos.OptionType)
		response.FCP_STRK_PRC = append(response.FCP_STRK_PRC, float32(pos.StrikePrice))
		response.FCP_UCC_CD = pos.UCCCode
		response.FCP_OPNPSTN_FLW =append(response.FCP_OPNPSTN_FLW, pos.OpenPstnFlow)
	}

	return response, nil
}
=======
	var fcpDetails []*pb.FcpDetail

	for _, pos := range positions {
		fcpDetail := &pb.FcpDetail{
			FFO_CONTRACT:     pos.Contract,
			FFO_PSTN:         pos.Position,
			FFO_QTY:          int32(pos.TotalQty),
			FFO_AVG_PRC:      float32(pos.AvgCostPrice),
			FCP_XCHNG_CD:     pos.ExchangeCode,
			FCP_IBUY_QTY:     int32(pos.BuyQty),
			FCP_CLM_MTCH_ACCNT: pos.ClaimMatchAccount,
			FCP_PRDCT_TYP:    pos.ProductType,
			FCP_INDSTK:       pos.IndexStock,
			FCP_UNDRLYNG:     pos.Underlying,
			FCP_EXPRY_DT:     pos.ExpiryDate,
			FCP_EXER_TYP:     pos.ExerciseType,
			FCP_OPT_TYP:      pos.OptionType,
			FCP_STRK_PRC:     float32(pos.StrikePrice),
			FCP_UCC_CD:       pos.UCCCode,
			FCP_OPNPSTN_FLW:  pos.OpenPstnFlow,
		}

		fcpDetails = append(fcpDetails, fcpDetail)
	}

	return &pb.FcpDetailListResponse{
		FcpDetails: fcpDetails,
	}, nil
}

>>>>>>> master
