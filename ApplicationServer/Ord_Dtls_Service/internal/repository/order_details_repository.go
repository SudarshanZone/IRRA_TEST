package repository

import (
	"fmt"
	"github.com/SudarshanZone/Ord_Dtls/internal/models"
	"gorm.io/gorm"
)

type OrderDetailsRepository struct {
    Db *gorm.DB
}

func (repo *OrderDetailsRepository) GetOrderDetailsByClaimMatchAccount(claimMatchAccount string) ([]models.OrderDetails, error) {
    var orderDetails []models.OrderDetails
    // query := `
    //     SELECT
    //         CASE
    //             WHEN FOD_UNDRLYNG IS NOT NULL THEN
    //                 CONCAT(FOD_UNDRLYNG, ' ', TO_CHAR(FOD_TRD_DT, 'DD-Mon-YYYY'))
    //             ELSE 'Unknown'
    //         END AS "ContractDescriptor",
    //         TO_CHAR(FOD_TRD_DT, 'DD-Mon-YYYY') AS "VTCDate",
    //         CASE
    //             WHEN FOD_ORDR_FLW = 'B' THEN 'BUY'
    //             WHEN FOD_ORDR_FLW = 'S' THEN 'SELL'
    //             ELSE ''
    //         END AS "BuySell",
    //         FOD_ORDR_TOT_QTY AS "Quantity",
    //         FOD_ORDR_STTS AS "Status",
    //         FOD_LMT_RT AS "OrderPrice",
    //         CASE
    //             WHEN FOD_ORDR_STTS = 'OPEN' THEN 'Yes'
    //             ELSE 'No'
    //         END AS "Open"
    //     FROM
    //         FOD_FO_ORDR_DTLS
    //     WHERE
    //         (FOD_ORDR_TOT_QTY != 0 OR FOD_LMT_RT IS NOT NULL)
    //         AND FOD_CLM_MTCH_ACCNT = ?;
    // `

    query := `SELECT
    CASE
        WHEN FOD_PRDCT_TYP = 'F' THEN
            'FUT-' || TRIM(FOD_UNDRLYNG) || '-' || TO_CHAR(FOD_EXPRY_DT, 'DD-Mon-YYYY')
        WHEN FOD_PRDCT_TYP = 'O' THEN
            'OPT-' || TRIM(FOD_UNDRLYNG) || '-' || TO_CHAR(FOD_EXPRY_DT, 'DD-Mon-YYYY') || '-' ||
            FOD_STRK_PRC || '-' ||
            CASE
                WHEN FOD_OPT_TYP = 'C' THEN 'CE'
                WHEN FOD_OPT_TYP = 'P' THEN 'PE'
                ELSE '*'
            END
        ELSE
            TRIM(FOD_UNDRLYNG) || '-' || TO_CHAR(FOD_EXPRY_DT, 'DD-Mon-YYYY')
    END AS "ContractDescriptor",
    TO_CHAR(FOD_TRD_DT, 'DD-Mon-YYYY') AS "VTCDate",
    CASE
        WHEN FOD_ORDR_FLW = 'B' THEN 'BUY'
        WHEN FOD_ORDR_FLW = 'S' THEN 'SELL'
        ELSE '*'
    END AS "BuySell",
    FOD_ORDR_TOT_QTY AS "Quantity",
    FOD_ORDR_STTS AS "Status",
    FOD_LMT_RT AS "OrderPrice",
    FOD_ORDR_TOT_QTY AS "Open"
FROM
    FOD_FO_ORDR_DTLS
WHERE
    (FOD_ORDR_TOT_QTY != 0 OR FOD_LMT_RT IS NOT NULL)
    AND FOD_CLM_MTCH_ACCNT = ?;
`
    err := repo.Db.Raw(query, claimMatchAccount).Scan(&orderDetails).Error
    if err != nil {
        return nil, fmt.Errorf("error fetching order details: %w", err)
    }
    
    return orderDetails, nil
}
