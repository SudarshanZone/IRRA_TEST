package service

import (
	"context"
	"fmt"
	pb "github.com/SudarshanZone/Open_Pos/generated"
	"github.com/SudarshanZone/Open_Pos/internal/repository"
)

type FnoPositionService struct {
	Repo repository.FnoPositionRepository
	pb.UnimplementedFnoPositionServiceServer
}

func (s *FnoPositionService) GetFNOPosition(ctx context.Context, req *pb.FnoPositionRequest) (*pb.FnoPositionResponse, error) {
	positions, err := s.Repo.GetPositionsByClaimMatchAccount(req.FCP_CLM_MTCH_ACCNT)
	if err != nil {
		return nil, fmt.Errorf("failed to get positions: %w", err)
	}

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
