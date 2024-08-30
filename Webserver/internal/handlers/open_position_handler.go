package handlers

import (
	//"context"
	"net/http"

	"github.com/gin-gonic/gin"
	log "github.com/sirupsen/logrus"
<<<<<<< HEAD

	// pb "github.com/SudarshanZone/Open_Pos/generated"
	// ob "github.com/SudarshanZone/Ord_Dtls/generated"
	// "github.com/SudarshanZone/Web_Server/internal/grpc"
=======
>>>>>>> master
)

func SetupRoutes(router *gin.Engine, facade Facade, logger *log.Entry) {
	router.GET("/getFNOPosition/:UCCID", func(c *gin.Context) {
		UCCID := c.Param("UCCID")

		// Log incoming request
		logger.WithFields(log.Fields{
			"endpoint": "/getFNOPosition",
			"UCCID":    UCCID,
		}).Info("Received request")

		resp, err := facade.GetFNOPosition(UCCID)
		if err != nil {
			logger.WithFields(log.Fields{
				"endpoint": "/getFNOPosition",
				"UCCID":    UCCID,
				"error":    err.Error(),
			}).Error("Error fetching FNO positions")
			c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to fetch FNO positions"})
			return
		}

		// Log successful response
		logger.WithFields(log.Fields{
			"endpoint": "/getFNOPosition",
			"UCCID":    UCCID,
		}).Info("Successfully fetched FNO positions")

		c.JSON(http.StatusOK, gin.H{"positions": resp})
	})

	router.GET("/getOrderDetails/:OrderID", func(c *gin.Context) {
		OrderID := c.Param("OrderID")

		// Log incoming request
		logger.WithFields(log.Fields{
			"endpoint": "/getOrderDetails",
			"OrderID":  OrderID,
		}).Info("Received request")

		resp, err := facade.GetOrderDetails(OrderID)
		if err != nil {
			logger.WithFields(log.Fields{
				"endpoint": "/getOrderDetails",
				"OrderID":  OrderID,
				"error":    err.Error(),
			}).Error("Error fetching order details")
			c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to fetch order details"})
			return
		}

		// Log successful response
		logger.WithFields(log.Fields{
			"endpoint": "/getOrderDetails",
			"OrderID":  OrderID,
		}).Info("Successfully fetched order details")

		c.JSON(http.StatusOK, gin.H{"orderDetails": resp})
	})
}
