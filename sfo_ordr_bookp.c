/*	Program	    			:	SFO_ORDR_BOOKP                                         */
/*                                                                            */
/*  Input             :	Required				                                      */
/*	                    FFO_USR_ID                                            */
/*											FFO_SSSN_ID																						*/
/*											FFO_EBA_MTCH_ACT_NO																		*/
/*											FFO_XCHNG_CD																					*/
/*											FFO_OPERATION_TYP																			*/
/*											FFO_ROUT_CRT                                          */
/*                                                                            */
/*											Optional																							*/
/*											FFO_PRDCT_TYP																					*/
/*											FFO_UNDRLYNG																					*/
/*											FFO_EXPRY_DT																					*/
/*											FFO_EXER_TYP																					*/
/*											FFO_OPT_TYP																						*/
/*											FFO_STRK_PRC																					*/
/*											FFO_ORDR_STTS																					*/
/*											FFO_FROM_DT																						*/
/*											FFO_TO_DT																							*/
/*											FFO_ACK_NMBR  																				*/
/*											FFO_PIPE_ID                                           */
/*                                                                            */
/*  Output            : FFO_ORDR_RFRNC  																			*/
/*											FFO_PIPE_ID                                           */
/*											FFO_XCHNG_CD                                          */
/*											FFO_PRDCT_TYP																					*/
/*											FFO_UNDRLYNG																					*/
/*											FFO_EXPRY_DT																					*/
/*											FFO_EXER_TYP																					*/
/*											FFO_OPT_TYP																						*/
/*											FFO_STRK_PRC																					*/
/*                      FFO_CTGRY_INDSTK                                      */
/*											FFO_ORDR_FLW																					*/
/*											FFO_LMT_MKT_SL_FLG																		*/
/*											FFO_DSCLSD_QTY																				*/
/*											FFO_ORD_TOT_QTY																				*/
/*											FFO_LMT_RT																						*/
/*											FFO_STP_LSS_TGR																				*/
/*											FFO_ORD_TYP																						*/
/*											FFO_ORD_VALID_DT																			*/
/*											FFO_TRD_DT																						*/
/*											FFO_ORDR_STTS																					*/
/*											FFO_EXEC_QTY																					*/
/*											FFO_CANCL_QTY																					*/
/*											FFO_EXPRD_QTY																					*/
/*											FFO_SETTLOR																						*/
/*											FFO_SPRD_ORD_REF																			*/
/*											FFO_ACK_NMBR																					*/
/*                      FFO_C_OPNPSTN_QTY                                     */
/*                      FFO_SERIES                                            */
/*                                                                            */
/*  Description       : This service retrieves the values of the entire order */
/*											book given different input parameters based on 				*/
/*											different needs. The different needs are described    */
/*											as different operation types.													*/
/*											A	-	Contract as Input																	*/
/*											B	-	Contract and Date as Input												*/
/*											C	-	Underlying as Input																*/
/*											D	-	Underlying and Date as Input											*/
/*											E	-	Status and Product as Input												*/
/*											F	-	Status, Product and Date as Input									*/
/*											G	-	Exchange ack no, Pipe id as Input									*/
/*                                                                            */
/*  Log               :	1.0		03-Oct-2001		Ramesh Reddy.V										*/
/*  Log               :	1.5		25-Sep-2004		Sangeet Sinha											*/
/*  Log               : 1.6   16-Feb-2007	  Vikash Kumar											*/
/*  Log               : 1.7   04-Dec-2007	  Vikash Kumar											*/
/*                    : 1.8   03-Jan-2008   Sushil Sharma                     */
/*                                                                            */
/*										:	1.9		11-May-2008		ROhit 														*/
/*                    : 2.1   07-May-2009		Vidyayini Krish										*/
/*                    : 2.2   03-Nov-2009		Sangeet Sinha										  */
/*										:	2.3		15-Nov-2010		Sandeep Patil											*/
/*										:	2.4		24-Dec-2010		Shailesh Hinge										*/
/*										:	2.5		15-Nov-2010		Sandeep Patil											*/
/*										: 2.6   16-Mar-2011		Navina														*/
/*										: 2.7		21-Jul-2011		Shamili														*/
/*                    : 2.8   12-Jan-2012   Sachin Birje                      */
/*										: 2.9 	26-Sep-2012	  Vishnu Nair												*/
/*                    : 3.0   28-Feb-2013   ERS changes (Diwakar)             */
/*										: 3.1 	11-Dec-2012	  Navina D. 												*/
/*                    : 3.2   07-Mar-2013   Navina D.                         */
/*                    : 3.3   07-May-2013   Sandeep Patil                     */
/*                    : 3.4   03-Jun-2013   Samip M 			                    */
/*                    : 3.5   12-Jul-2013   Sandeep Patil 			              */
/*										: 3.6   19-Sep-2013   Shailesh Sabale                   */
/*                    : 3.7   10-Oct-2013   Swati A.B                         */
/*                    : 3.8   21-Jan-2014   Bhushan Sonwane                   */
/*                    : 3.9   30-Apr-2014   Samip M                           */
/*                    : 4.0   26-May-2014   Bhushan Sonwane                   */
/*                    : 4.1   08-Jul-2014   Vishnu Nair												*/
/*                    : 4.2   28-Aug-2014   Samip M														*/
/*                    : 4.3   31-Mar-2015   Anand Dhopte                      */
/*                    : 4.4   04-Apr-2015   Tanmay Warkhade                   */
/*                    : 4.5   08-May-2015   Anand Dhopte                      */
/*                    : 4.6   26-May-2015   Sachin Birje                      */
/*                    : 4.7   06-Jul-2015   Bhupendra Malik                   */
/*                    : 4.8   23-Sep-2015   Samip M														*/
/*                    : 4.9   06-Oct-2015   Bhupendra Malik                   */
/*                    : 5.0   14-Dec-2015   Anand Dhopte                      */
/*                    : 5.1   06-Jan-2015   Anand Dhopte                      */
/*                    : 5.2   18-May-2016   Anand Dhopte                      */
/*                    : 5.3   05-Jul-2016   Sachin Birje                      */
/*                    : 5.4   02-Aug-2016   Vishal Borhade                    */
/*                    : 5.5   18-Aug-2016   Vishal Borhade/Kishor Borkar      */ 
/*                    : 5.6   02-Jan-2016   Anand Dhopte                      */
/*                    : 5.7   10-Jan-2016   Mrinal Kishore                    */
/*                    : 5.9   16-Feb-2017   Anand Dhopte                      */
/*                    : 6.0   06-Apr-2017   Anand Dhopte                      */
/*                    : 6.1   17-Oct-2017   Samip M														*/
/*                    : 6.3   08-Apr-2019   Mrinal Kishore                    */
/*                    : 6.4   12-Nov-2019   Navina D.                        */  
/*                    : 6.5   03-Jul-2020   Sanjeet P.                        */
/*                    : 6.6   22-Jan-2021   Anuj Pancholi                     */
/*                    : 6.7   28-Apr-2021   Navina D                          */
/*										:	6.8		11-Aug-2021		Kiran Itkar												*/
/*										:	6.9		25-Nov-2021		Shlok Ghan												*/
/*										:	7.0		7-Nov-2021		Suchita DAbir									*/
/*                    : 7.1   28-Sep-2021   Kalpesh Patil                     */
/*                    : 7.2   04-May-2022   Sachin Birje                      */
/*                    : 7.3   14-Sep-2022   Sachin Birje                      */
/*                    : 7.4   30-Sep-2022   Ravi Malla                      	*/
/*                    : 7.5   22-Dec-2022   Ravi Malla                      	*/
/*										: 7.6   17-May-2023   Vipul Sharma											*/
/*                    : 7.7   22-Jun-2023   Devesh Chawda                     */
/*                    : 7.8   09-Nov-2023   Samip M                           */
/*                    : 7.9   07-Oct-2023   Naveena R.                        */
/*                    : 8.0   11-Dec-2023   Naveena R.                        */
/*                    : 8.1   12-Dec-2023   Samip M														*/
/*                    : 8.2   28-Dec-2023   Samip M														*/
/*                    : 8.3   10-Jan-2024   Samip M														*/
/*                    : 8.4   31-Jan-2024   Nikhil Soni                       */
/*                    : 8.5   31-Jan-2024   Sachin Birje  										*/
/*                    : 8.6   31-Jan-2024   Nikhil Soni                       */
/*                    : 8.8   01-Apr-2024  Adleen/Ashwini/Vishal              */
/*                    : 8.9   04-Apr-2024  Nikhil Soni                          */
/******************************************************************************/
/* 1.0		-		New Release                                                     */
/* 1.1		-		Changes for BP                                                  */
/* 1.2		-		CR1038 Channel for Super user login                             */
/* 1.3		-		Channel for FBS																									*/
/* 1.4		-		Changes for merging DT wraper service and underlying service.		*/
/* 1.5		-		Changes for removal of locking mechanism of FNO in placement		*/
/* 1.6    -   Changes for DLRevamp returning separate channel for DBC handling*/ 
/*        -   New FML FFO_SERIES used to hold the channel.-VIKASH             */
/*				-		New FML FFO_C_OPNPSTN_QTY to hold open position Qty.-SUSHIL			*/
/*				-		FML FFO_SUB_BUF_CNT not required	- SUSHIL											*/
/*				-		Commenting of request time -RANJIT															*/
/* 1.7    -   Changes for NNF808 increase in size of trade no. and order no.  */
/* 1.8    -   AIX Migration                                                   */
/* 1.9    -		Change for Reallocation																					*/
/* 2.0    -   IFX changes by zubin  on 04/04/2008                             */
/* 2.1    -   Changes for Investment strategy orders                      		*/
/* 2.2    -   Qyery on Ack commented by sangeet			                      		*/
/* 2.3		-		Online BPID Changes 																						*/
/* 2.4		-	  CRSCM44262-Display order book records in descending order				*/
/* 2.5		-		Silver Light Changes																						*/
/* 2.6		-		FDM_DT_MTCH,FTO_FO_TMP_ORD_DTLS Removed and query Optimization	*/
/* 2.7		-   Mobile App																											*/
/* 2.8    -   FNO BSE Changes                                                 */
/* 2.9 		- 	Change for Iphone and Windows APP																*/
/* 3.0    -   To show channel ERS for ERS type customer                       */
/* 3.1		-   SLTP FuturePLUS handling                                        */
/* 3.2    -   SPAN FuturePLUS handling                                        */
/* 3.3    -   Windows 7 Changes                                               */
/* 3.4    -   Order Book optimization and bulk comments of 2.6 removed        */
/* 3.5		-		CN2 channel handling introduced for DL.Net											*/
/* 3.6    -   OptionPlus handling																							*/
/* 3.7    -   SLTP FuturePLUS in RIA                                          */
/* 3.8    -   Contract Note Changes                                           */
/* 3.9    -   Inclusion of Advisor order book                                 */
/* 4.0		-		OptionPlus in RIA                                               */
/* 4.1		-		Changes for HTMl 5																							*/
/* 4.2		-		View to FML changes																							*/
/* 4.3    -   Optimization - DB Hits Reduction                                */
/* 4.4    -   Enabling Logs for From date and To date                         */
/* 4.5    -   Debug Level Changes and unnecessary Logs commented              */
/* 4.6    -   FNO VTC order Changes                                           */
/* 4.7    -   Market to Limit Future Plus SLTP                                */
/* 4.8    -   Bug fix for tpfree																							*/
/* 4.9    -   Market to Limit Option Plus                                     */
/* 5.0    -   SLTP FP & Option Plus Changes for Other Front Ends              */
/* 5.1    -   IDirect Lite Channel Handling Changes                           */
/* 5.2    -   Debug Level Changes and unnecessary Logs commented              */
/* 5.3    -   Debug Level changes & Memory issue fix                          */
/* 5.4    -   Exchange Trade Date is passed to front end to reduce extra 			*/
/*						service call (sfo_exchngstts.pc).Front End will use this date to*/
/*						display REORDER link.																						*/
/* 5.5    -   Future Trail                                                    */
/* 5.6    -   Handling for product type "ALL" on LBS                          */
/* 5.7    -   Channel handling changes for Other Front End                    */
/* 5.9    -   VTC Order Log changes for Other Front End                       */
/* 6.0    -   Optimization Changes                                            */
/* 6.1    -   Stop VTC feature																								*/
/* 6.3    -   Rollover with Spread Changes                                    */
/* 6.4    -   Sensibull Integration                                           */
/* 6.5    -   System Order on Advisor Trading Screen                          */    
/* 6.6    -   Vendor Validation Changes                                       */                
/* 6.7    -   All product tag order ref handling for itrade                   */    
/* 6.8		-		Change for single espid selection																*/
/* 6.9		-		CR_ISEC14_150651  One Click																			*/
/* 7.0    -   Minor changes (Order Placement Timestamp on OrderBook)          */
/* 7.1    -   Profit order modify/cancel flag changes                         */
/* 7.2    -   CR-ISEC14-169739 -Introduction of Algorithm Trading Strategies  */
/* 7.3    -   API Response Optimization Changes                               */
/* 7.4    -   Flash Trade Changes 																						*/
/* 7.5    -   Flash Trade OptionPlus Changes																	*/
/* 7.6    -   Adding debug levels																							*/
/* 7.7    -   RQ:3117 GTT in FNO                                              */
/* 7.8    -   Order Book Restriction for Muhurat Trading                      */
/* 7.9    -   RQ:3544 BSE Derivatives                                         */
/* 8.0    -   Order Book Restriction for Muhurat Trading                      */
/* 8.1    -   Panic flag introduction																					*/
/* 8.2    -   Log flag enablement and History issue														*/
/* 8.3    -   Order Book history optimization																	*/
/* 8.4    -   RQ10431 Order Book Pagination                            				*/
/* 8.5    -   RQ:10251 Order Book Panic for Trading Screen                    */
/* 8.6    -   RQ:10431  Removed comment and add ltp           									*/
/* 8.7    -   Trading screen history Flag enable   nikhil soni  */
/* 8.8    -   RQ_11478_ALL Excahnge code                                      */
/* 8.9    -   RQ:13686 Invalid Page number error handling with print total page count (Nikhil Soni)  */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <atmi.h>
#include <fml32.h>
#include <sqlca.h>
#include <fo.h>
#include <fo_fml_def.h>
/** #include <fo_view_def.h> **/ /** Commented for Ver 4.2 **/
#include <fml_rout.h>				/** Added for Ver 4.2 */
#include <fo_struct_def.h>	/** Added for Ver 4.2 */
#include <fn_session.h>
#include <fn_tuxlib.h>
#include <fn_ddr.h>
#include <eba_to_ors.h>					/** Added in ver 1.7 **/
#include <fn_log.h>       			/* Ver 1.8 : Added  */
#include <fn_getref.h>    			/* Ver 1.8 : Added  */
#include <fn_read_debug_lvl.h>  /*  Ver 1.8 : Added   */
#include <fn_val_ord.h>         /* Ver 6.4 */

#define MIN 0
#define MAX 1
#define BUF_MULTIPLY 1
#define PAGE_MAX_REC 50 /* ver 8.4 */

void SFO_ORDR_BOOKP( TPSVCINFO *rqst )
{
	FBFR32 *ptr_fml_ibuf;
  FBFR32 *ptr_fml_obuf;

	EXEC SQL INCLUDE "table/ifx_usr_mstr.h"; /*ver 2.0*/
  EXEC SQL INCLUDE "table/icd_info_client_dtls.h"; /*** Ver 6.4 ***/

  char c_src_flg ;
	char c_ServiceName[33];
	char c_ServiceName1[33];		/** Ver 8.1 **/
	int i_fpe_flag = 0;
	int i_fpe_hstry_dsbl_flag = 0;
	int i_fpe_log_enblmnt_flag = 0;	/** Ver 8.2 **/
  int i_trdngscrn_flag= 0;  /** Ver 8.5 **/
  int i_trdngscrn_hstry_dsbl_flag=0; /** Ver 8.7 **/
  char c_errmsg[256];
	char c_dbc_channel[7+1];				/******	ver 1.6  DL REVAMP	******/
	char c_option_type;
	char c_mod_can_flg = 'N';
	char c_rqst_typ ;
	char c_plcd_stts ;
  char c_min_pipe_id[3];			/***	Ver	2.8	***/
  char c_max_pipe_id[3];			/***	Ver	2.8	***/
	char c_cntrct_num[25];			/*** Ver 4,1 ***/
	int	 cnt_rec=0;/*Ver 2.0*/	
	char c_1clk_flg='\0';			/*** ver 6.9  ***/
   /*** Ver 4.7 Starts ***/
  char c_tag_ordr_rfrnce [19];
  char c_tag_ord_typ ='\0';
  char c_tag_ord_stts = '\0';
  char c_tag_frsh_cvr_flg = '\0';
  char c_cancel_can_flg='N';
  char c_chk_new_site_flg='O';
  long l_tag_ord_lmt_rt =0 ;
  long l_tag_sltp_tgr =0;
  long l_tag_exe_qty =0;
  long l_tag_can_qty = 0;
  long l_tag_exprd_qty = 0;
  long l_tag_open_qty = 0;
  long l_tag_ordr_tot_qty = 0;
  /*** Ver 4.7 Ends ***/
  char c_spcl_flg ='\0';

	char c_stop_vtc_flg = 'N';		/** Ver 6.1 **/

	varchar	c_frm_dt[ LEN_DATE ];
	varchar c_to_dt[ LEN_DATE ];

  int  i_returncode;
  int  i_err[7];          /*** Ver 2.7 ***//** Changed from 5 to 6 for Ver 3.9 **//** Changed from 6 to 7 for ver 6.5 ***/             
  int  i_ferr[7];         /*** Ver 2.7 ***//** Changed from 5 to 6 for Ver 3.9 **//*changed from 6 to 7 for ver 6.5**/
  int  i_cnt;
  int  i_counter = 1;
	int i_rec_count = 0;				/*** * ver 1.4 * Commented In Ver 4.3 As it is not used	 *** Uncommented in Ver 6.4 ***/
	int k;									/* ver 1.4 */
	int  i_catagory_types;  /*Ver 3.0 */
  int  i_loop_cnt=0;      /* Ver 4.6 */
  int  i_vtc_cnt=0;       /* Ver 4.6 */
	int	rec_price_rjct = 0;		/** Ver 6.1 **/

  long l_tot_pages=0;  /** Ver 8.4 **/
  long l_start_rec_no=0; /** Ver 8.4 **/
  long l_end_rec_no=0; /** Ver 8.4 **/
  long l_page_no=0;  /** Ver 8.4 **/
  long l_page_rec_cnt=0;  /** Ver 8.4 **/ 
  char c_last_leg=0;      /** Ver 8.4 **/
  int  i_first_order=0;      /** Ver 8.4 **/

	/***
 	long li_rec_cnt_contract_date;
	long li_rec_cnt_undrlng_date; 
	
	Commented In Ver 4.3 ***/

	long li_rec_cnt_status_date = 0 ; 	/***	Initialised To 0 In Ver 4.3	***/
	long li_rec_main_exists;
	long l_bufferlength;
	long l_open_qty = 0;		 /****** ver 1.6  DL REVAMP  ******/
  long li_rec_cnt_adv = 0;    /*** Ver 3.9 ***/ 

	long l_ltp_prc	=	0.00;	 /***	Ver	2.5	***/
	long l_brkg_val = 0;  /** Ver 4.1 **/
	long l_exctd_rt = 0;  /** Ver 4.1 **/
	
	double  d_trd_val = 0; 	/** Ver 4.1 **/
	double d_mrgn_blk = 0.00;		/*** Ver 3.1 ***/
	double d_trail_amt=0.0;         /** Ver 5.5 **/
  double d_trl_upd_cond_val=0.0;  /** Ver 5.5 **/
  double d_incrmnt_prc=0.0;       /** Ver 5.5 **/

	char c_fc_flg = '\0';				/*** Ver 3.1 ***/
	char c_frsh_ord_stts  = '\0';       /*** Ver 3.1 ***/
	char c_spn_flg = '\0';			/*** Ver 3.2 ***/
  char c_vtc_ord_stts='\0';  /* Ver 4.6 */
  char c_sqoff_at_mkt = 'N';      /***  Ver 5.0 ***/
  char c_can_srv_call = '\0';     /***  Ver 5.0 ***/
  char c_mod_srv_call = '\0';     /***  Ver 5.0 ***/
	char c_prcimpv_flg = '\0';         /** Ver 5.5 **/
  char c_sltp_trail_flag = '\0';     /** Ver 5.5 **/

	char c_prft_pend = 'N';                         /*** Ver 7.1  ***/
  char c_prft_penordrref[19]="\0";      /*** Ver 7.1  ***/
  long l_prft_lmt_rt = 0;     /** ver 7.1  **/

  char c_sltp_ord_rfrnc_prev[19]; /* Ver 8.4 */
  char c_spl_flg_prev='\0';            /* Ver 8.4 */ 
  char c_ordr_rfrnc_prev[19];     /* Ver 8.4 */
  char c_cln_mtch_accnt_prev[11]; /* Ver 8.4 */
  
	EXEC SQL BEGIN DECLARE SECTION;
	  struct vw_contract st_cntrct;
    struct vw_orderbook *ptr_st_orderbook;
    struct vw_usr_prfl st_usr_prfl;
		sql_cursor	sys_cursor;
		varchar c_expiry_dt[ LEN_DATE ];
		varchar c_exp_date[ LEN_DATE ];
		varchar c_valid_date[ LEN_DATE ];
		varchar c_trd_date[ LEN_DATE ];
		/*varchar c_request_tm[ LEN_DATE ];**/  /*  commmented in ver 1.6   */
		varchar c_ack_time[ LEN_DATE ]; /* ver 1.4 */
		varchar c_rqst_time[ LEN_DATE ]; /* ver 6.4 */
		varchar c_ordbk_seq[25];     /***  Ver 2.5 ***/
    varchar c_nxt_trd_dt[9];			/*** Ver 4.3 ***/
	  varchar c_nxt_trade_dt[11];     /** Ver 5.4 **/
		char c_opr_typ;
		char c_is_flg = 'N'; 										/* 2.1 */
		char c_ordr_stts;
		char c_order_stts;
		char c_date_flag = 'Y';
		char c_mtch_accnt_no[11];
		char c_exchange_cd[4];
		char c_product_typ;
		char c_underlying[7];
		char c_exercise_type;
		char c_min_ref_num[19];
		char c_max_ref_num[19];
		long li_strike_price;
		char c_pipe_id[3];
    /** char c_xchng_ack[16]; commented in ver 1.7 **/
    char c_xchng_ack[ LEN_XCHNG_ACK ]; /** Added in ver 1.7 **/
    char c_remarks[257];
		char c_user_id[ 15 ];				/*** Ver 2.6 ***/
		varchar c_ordr_ref [ 19 ];	/*** Ver 2.7 ***/
    char c_advisor_id[20];   /*** Ver 3.9 ***/
    char c_sys_ordr_flg = 'N' ;     /*** Ver 6.5***/                
		varchar c_ven_id[50+1];  /*** Ver 6.4 ***/
		char c_ven_nm[15] = "\0";	/*** Ver 6.4 ***/
  	varchar c_esp_id[50+1];  /*** Ver 6.4 ***/
		char c_esp_nm[15] = "\0";	/*** Ver 6.4 ***/
		char c_apisrc_flg = '\0'; /*** Ver 6.4 ***/

  EXEC SQL END DECLARE SECTION;

	struct vw_err_msg st_err_msg;

	ptr_fml_ibuf = (FBFR32 *)rqst->data;
  strcpy( c_ServiceName, rqst->name );
	INITDBGLVL(c_ServiceName);            /*  Ver 1.8 : Added   */


	MEMSET(c_rqst_time);	/*** Ver 6.4 ***/
	MEMSET(c_ack_time);		/*** Ver 6.4 ***/
	MEMSET(c_esp_id); 	/*** Ver 6.4 ***/
	/*** Commented for Ver 4.2 *************
	i_returncode = Fvftos32( ptr_fml_ibuf,
                           (char *) &st_usr_prfl,
                           "vw_usr_prfl" );
  if ( i_returncode == -1 )
  {
    fn_errlog( c_ServiceName, "S31005", FMLMSG, c_errmsg  );
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }
	***** Ver 4.2 ***/

 /** Fprint32(ptr_fml_ibuf); **/

	/***** Added for Ver 4.2 ***/
  i_returncode = fn_unpack_fmltovar_dflt ( c_ServiceName,
                                      c_errmsg,
                                      ptr_fml_ibuf,
                                      16,
                                      FFO_USR_ID,(char *)st_usr_prfl.c_user_id, "NULL",
                                      FFO_SSSN_ID,(char*)&st_usr_prfl.l_session_id, "NULL",
                                      FFO_EBA_MTCH_ACT_NO,(char*)st_usr_prfl.c_cln_mtch_accnt, "NULL",
																			FFO_PIPE_ID, (char*)st_usr_prfl.c_pipe_id, "*",
																			FFO_ROUT_CRT, (char*)st_usr_prfl.c_rout_crt, "NULL",
                                      FFO_EBA_CNTRCT_ID,(char *)&st_cntrct.l_eba_cntrct_id, "-1",
                                      FFO_XCHNG_CD,(char*)st_cntrct.c_xchng_cd, "NULL",
                                      FFO_PRDCT_TYP,(char*)&st_cntrct.c_prd_typ, "*",
                                      FFO_UNDRLYNG, (char*)st_cntrct.c_undrlyng, "*",
                                      FFO_EXPRY_DT, (char*)st_cntrct.c_expry_dt, "*",
				      												FFO_EXER_TYP, (char*)&st_cntrct.c_exrc_typ, "*",
				      												FFO_OPT_TYP, (char*)&st_cntrct.c_opt_typ, "-",
				      												FFO_STRK_PRC, (char*)&st_cntrct.l_strike_prc, "-1",
				      												FFO_CTGRY_INDSTK, (char*)&st_cntrct.c_ctgry_indstk, "*",
				      												FFO_CA_LVL, (char*)&st_cntrct.l_ca_lvl, "-1",
																      FFO_RQST_TYP, (char*)&st_cntrct.c_rqst_typ, "*");

  if( i_returncode != 0 )
  {
   fn_errlog( c_ServiceName, "S31010", FMLMSG, c_errmsg  );
   Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
   tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }

	/******** Ver 4.2 *************/
  /*** Ver 8.4 Starts Here **/
  if (Fget32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_page_no,0)==-1)
  {
    if( Ferror32 == FNOTPRES )
    {
      l_page_no=1; 
    }
    else
    {
      fn_errlog( c_ServiceName, "S31015", SQLMSG, c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
  }
  /*** Ver 8.4 Ends here ****/

  /*** Added for Order Routing ***/
  fn_init_ddr_val ( st_usr_prfl.c_rout_crt );

	/** Added for ver 8.1 **/

	strcpy(c_ServiceName1,c_ServiceName);
	rtrim(c_ServiceName1);

  if( DEBUG_MSG_LVL_3 )
	{
		fn_userlog(c_ServiceName,"Service Name :%s:",c_ServiceName1);
	}

  i_trdngscrn_hstry_dsbl_flag=0; /** Ver 8.7 **/
  i_trdngscrn_flag=0;  /** Ver 8.5 **/
	EXEC SQL
		SELECT NVL(FPE_FLAG,0), NVL(FPE_HSTRY_DSBL_FLAG,0), NVL(FPE_LOG_ENBLMNT_FLAG,0),NVL(FPE_PAGE_RECCNT,50),/**Added for Ver 8.2 Log**/
           NVL(FPE_TRDNGSCRN_FLAG,0),NVL(FPE_TRDNGSCRN_HST_DSBL_FLAG,0)  /** Ver 8.7 nikhil **/   /** Ver 8.5 **/
		INTO :i_fpe_flag,:i_fpe_hstry_dsbl_flag,:i_fpe_log_enblmnt_flag,:l_page_rec_cnt,
         :i_trdngscrn_flag ,:i_trdngscrn_hstry_dsbl_flag       /** Ver 8.5 **/  /** added ver 8.7 trading screen hist enab flg **/   
		FROM FPE_FO_PANIC_ENLMNT
		WHERE FPE_SERVICE = :c_ServiceName1;

  if(  SQLCODE != 0 && SQLCODE != NO_DATA_FOUND)
  {
   	fn_errlog( c_ServiceName, "S31020", SQLMSG, c_err_msg);
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 ); 
  }
	else if(SQLCODE == NO_DATA_FOUND)
	{
		i_fpe_flag = 0;
		i_fpe_hstry_dsbl_flag = 0;
		i_fpe_log_enblmnt_flag = 0;		/** Ver 8.2 **/
	}

  if( DEBUG_MSG_LVL_3 )
	{
		fn_userlog(c_ServiceName,"Value of d_fpe_flag :%d:",i_fpe_flag);
		fn_userlog(c_ServiceName,"Value of i_fpe_hstry_dsbl_flag :%d:",i_fpe_hstry_dsbl_flag);
		fn_userlog(c_ServiceName,"Value of i_fpe_log_enblmnt_flag :%d:",i_fpe_log_enblmnt_flag);	/** Ver 8.2 **/
	}

	if(i_fpe_flag == 1)
	{
    fn_userlog( c_ServiceName,"Please try again in a moment.");
    strcpy(c_errmsg,"Please try again in a moment.");
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
	}

	/** End for ver 8.1 **/

  /*** Ver 8.5 Starts Here **/
  if ( strcmp( st_usr_prfl.c_user_id, "system" )== 0  && st_usr_prfl.l_session_id == 0 ) /** Do not allo trading screen order book **/
  {  /** ver 8.7 nikhil add user id **/
    if( i_trdngscrn_flag == 1 )
    {
      fn_userlog( c_ServiceName,"Please try again in a moment.");
      strcpy(c_errmsg,"Please try again in a moment.");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
  }
  /*** Ver 8.5 Ends here ***/ 


  /*** Ver 8.4 Starts Here ***/
  l_end_rec_no = l_page_rec_cnt * l_page_no;
  l_start_rec_no = (l_end_rec_no - l_page_rec_cnt)+1;
  if(DEBUG_MSG_LVL_3)
  {
    fn_userlog(c_ServiceName,"Page No:%ld: Index Start:%ld: Index End:%ld:",l_page_no,l_start_rec_no,l_end_rec_no);
  }
  /*** Ver 8.4 Ends Here ***/


  /*** Ver 7.3 Starts Here ***/
  rtrim(st_usr_prfl.c_cln_mtch_accnt);
  if(strncmp(st_usr_prfl.c_cln_mtch_accnt,"NA",2) == 0 )
  {
    if(st_usr_prfl.c_user_id[0] == BPID)
    {
      EXEC SQL
          SELECT MTCH
          INTO   :st_usr_prfl.c_cln_mtch_accnt
          FROM
          (
            SELECT  UAC_CLM_MTCH_ACCNT MTCH
            FROM    CLM_CLNT_MSTR,
                    UAC_USR_ACCNTS
            WHERE   CLM_BP_ID                     = :st_usr_prfl.c_user_id
            AND     CLM_MTCH_ACCNT                = UAC_CLM_MTCH_ACCNT
            AND     UAC_ACT_DEACT_FLG             IN ('A','X')
            AND     CLM_ALIAS_NAME                IS NOT NULL
            ORDER BY CLM_MTCH_ACCNT
          )
          WHERE ROWNUM = 1;

       if(  SQLCODE != 0 )
       {
         fn_errlog( c_ServiceName, "S31025", SQLMSG, c_err_msg);
         Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
         tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 ); 
       }
    }
    else
    {
      EXEC SQL
        SELECT MTCH
          INTO   :st_usr_prfl.c_cln_mtch_accnt
          FROM
            (
               SELECT  UAC_CLM_MTCH_ACCNT MTCH
                 FROM  UAC_USR_ACCNTS
                WHERE  UAC_USR_ID  = :st_usr_prfl.c_user_id
                  AND  UAC_ACT_DEACT_FLG IN('A','X')
             ORDER BY  UAC_ACT_DEACT_FLG
            )
        WHERE ROWNUM = 1;
      if(  SQLCODE != 0 )
      {
        fn_errlog( c_ServiceName, "S31030", SQLMSG, c_err_msg);
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 ); 
      }
    }
  } 
  /*** Ver 7.3 Ends Here ****/

	strcpy ( ( char * )c_mtch_accnt_no, st_usr_prfl.c_cln_mtch_accnt );

	if( DEBUG_MSG_LVL_3 ) 
	{
		fn_userlog(c_ServiceName, "***START OF SFO_ORDR_BOOKP for :%s: ***",st_usr_prfl.c_cln_mtch_accnt);
	}

if( DEBUG_MSG_LVL_3 )
  {
    fn_userlog(c_ServiceName, "**user id for FFO_USR_ID  :%s: ***",st_usr_prfl.c_user_id);
    fn_userlog(c_ServiceName,"session id FFO_SSSN_ID unpack data :%ld:",st_usr_prfl.l_session_id);
    fn_userlog(c_ServiceName,"pipe id FFO_PIPE_ID :%s:",st_usr_prfl.c_pipe_id);			/*** change %ld to %s in 6.8 ***/
    fn_userlog(c_ServiceName,"rout crt FFO_ROUT_CRT :%s:",st_usr_prfl.c_rout_crt);
    fn_userlog(c_ServiceName,"contract id FFO_EBA_CNTRCT_ID :%ld:",st_cntrct.l_eba_cntrct_id);	/*** change %s to %ld in 6.8 ***/
    fn_userlog(c_ServiceName,"exchange id FFO_XCHNG_CD :%s:",st_cntrct.c_xchng_cd);
    fn_userlog(c_ServiceName,"product type FFO_PRDCT_TYP :%c:",st_cntrct.c_prd_typ);
    fn_userlog(c_ServiceName,"stock underlying FFO_UNDRLYNG :%s:",st_cntrct.c_undrlyng);
    fn_userlog(c_ServiceName,"expire date FFO_EXPRY_DT :%s:",st_cntrct.c_expry_dt);
    fn_userlog(c_ServiceName,"exer type FFO_EXER_TYP:%c:",st_cntrct.c_exrc_typ);		/*** change %s to %c in 6.8 ***/
    fn_userlog(c_ServiceName,"option type FFO_OPT_TYP :%c:",st_cntrct.c_opt_typ);
    fn_userlog(c_ServiceName,"strike price FFO_STRK_PRC :%ld:",st_cntrct.l_strike_prc); 
    fn_userlog(c_ServiceName,"indstk FFO_CTGRY_INDSTK :%c:",st_cntrct.c_ctgry_indstk);	/*** change %s to %c in 6.8 ***/
    fn_userlog(c_ServiceName,"ca lvl FFO_CA_LVL :%ld:",st_cntrct.l_ca_lvl);							/*** change %c to %ld in 6.8 ***/
    fn_userlog(c_ServiceName,"request type FFO_RQST_TYP :%c:",st_cntrct.c_rqst_typ);		/*** change %s to %c in 6.8 ***/

  }



	
	/****** Added in Ver 2.0 for IFX **********/
  if (Fget32(ptr_fml_ibuf,FFO_BAT_TAG,0,(char *)sql_ifx_acc_id.arr,0)==-1)
  {
    if( Ferror32 == FNOTPRES )
    {
      strcpy((char *)sql_ifx_acc_id.arr, "0");
    }
    else
    {
      fn_errlog( c_ServiceName, "S31035", SQLMSG, c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
  }

  SETLEN(sql_ifx_acc_id);

	/*** Ver 6.4 starts here ***/
	MEMSET(c_ven_id);
	
	i_returncode = Fget32 ( ptr_fml_ibuf, FFO_UPLD_MTCH_FLG, 0, (char *)&c_apisrc_flg, 0 );
	if( i_returncode == -1 && Ferror32 != FNOTPRES )
	{
      fn_errlog( c_ServiceName, "S31040", FMLMSG, c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
	}

	if( DEBUG_MSG_LVL_1 ) 
	{
		fn_userlog(c_ServiceName,"API Source Flag :%c:",c_apisrc_flg);
	}

	if (c_apisrc_flg == 'A') /*** API Call ***/
	{
		if (Fget32(ptr_fml_ibuf,FFO_USER_CODE,0,(char *)c_ven_id.arr, 0) == -1 )	/*** Get vendor user id (IAD_USER_ID) from API using Public Key ***/
		{
			if( Ferror32 == FNOTPRES )
			{
				if( DEBUG_MSG_LVL_1 ) /* Added debug level Ver 7.6 */
				{
					fn_userlog(c_ServiceName,"Normal call");
				}
				strcpy(c_ven_id.arr,"%");
			}
			else
			{
				fn_errlog( c_ServiceName, "S31045", FMLMSG, c_errmsg  );
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
				tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}
		}

    MEMSET(c_user_id);
    strcpy ( c_user_id, st_usr_prfl.c_user_id);

    
   if ( strcmp(c_ven_id.arr,"%") != 0)  /** ver 6.6 **/ 
   { 

     i_returncode = fn_chk_vendor( c_ServiceName,
                                    c_user_id,
			                              c_ven_id.arr,
                      							c_ven_nm,
                        			      &st_err_msg
                      			    );    
     if ( i_returncode == -1 )
     {
        fn_errlog( c_ServiceName, "S31050","Error in function fn_chk_vendor",c_errmsg);
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, st_err_msg.c_err_msg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     } 

    } 

		SETLEN(c_ven_id);

		if( DEBUG_MSG_LVL_1 ) 
		{
			fn_userlog(c_ServiceName,"Vendor Id = ESP_ID is :%s: Vendor Name:%s:",c_ven_id.arr,c_ven_nm);
		}
		
		if(strcmp(c_ven_nm,"SENSIBULL") == 0 )
		{

    	/**** User with no active plan can plc orders and view orderbook | Order plc only after TNC acceptance so removed chk from ordrbook  ***
			i_returncode = fn_chk_vendor_validity( 	c_ServiceName,
                                  						c_user_id,
                                  						&st_err_msg
                                						);
    	if ( i_returncode == -1 )
    	{
        fn_errlog( c_ServiceName, "S31055","Error in function fn_chk_vendor_validity",c_errmsg);
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, st_err_msg.c_err_msg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    	}
      i_returncode = fn_chk_sensibull_tnc(  c_ServiceName,
                                            c_user_id,
                                            &st_err_msg
                                          );
      if ( i_returncode == -1 )
      {
        fn_errlog( c_ServiceName, "S31060","Error in function fn_chk_sensibull_tnc",c_errmsg);
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, st_err_msg.c_err_msg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
			***/

			if( c_user_id[0] == BPID )
			{
				fn_userlog(c_ServiceName,"Since you are Attached to a Direct Business Catalyst,Sensibull is desabled");
        fn_errlog( c_ServiceName, "B35018", "",c_errmsg );
				strcpy(c_errmsg,"Since you are Attached to a Direct Business Catalyst,Sensibull is desabled");
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}

			EXEC SQL
        SELECT  ICD_CUST_TYPE
        INTO    :sql_icd_cust_type
        FROM    ICD_INFO_CLIENT_DTLS,
        IAI_INFO_ACCOUNT_INFO
        WHERE   ICD_SERIAL_NO = IAI_SERIAL_NO
        AND     IAI_MATCH_ACCOUNT_NO  = :c_mtch_accnt_no;
      if ( SQLCODE != 0 )
      {
        fn_errlog( c_ServiceName, "S31065",SQLMSG,c_errmsg);
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

			SETNULL(sql_icd_cust_type);

      if(strcmp(sql_icd_cust_type.arr,"NRI") == 0)
      {
        fn_userlog( c_ServiceName, "NRI Customer Trying To Place Order from SENSIBULL");
        fn_errlog( c_ServiceName, "S31070", "NRI Customer can not access Orderbook from SENSIBULL",c_errmsg);
        strcpy(c_errmsg," NRI Customer Trying To Place Order from SENSIBULL.");
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
		}
		else
		{
      /*************** commented in ver 6.6 *************************
      fn_userlog( c_ServiceName, "Invalid Vendor" );
      fn_errlog( c_ServiceName, "S31075","InValid Vendor.",c_errmsg );
      strcpy( c_errmsg,"InValid Vendor.");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      ***************************************************************/
			if(DEBUG_MSG_LVL_1)  /* Added debug level Ver 7.6 */
			{
      	fn_userlog(c_ServiceName,"Call from Vendor with ESP_ID :%s: Vendor Name:%s:",c_ven_id.arr,c_ven_nm);  /** ver 6.6 **/
			}
		}
	}
	else 
	{
		strcpy(c_ven_id.arr,"%");
	}

	SETLEN(c_ven_id);
	/*** Ver 6.4 ends here ***/
  
  if( DEBUG_MSG_LVL_3 )   /*** Ver 4.5 ***/
  {
    fn_userlog(c_ServiceName,"ifx acc id is <%s>",(char *)sql_ifx_acc_id.arr);
  } 

  if (strcmp((char *)sql_ifx_acc_id.arr,"0")!=0)
  {
    EXEC SQL
      SELECT  count(*)
      INTO    :cnt_rec
      FROM    uac_usr_accnts,ifx_usr_mstr
      WHERE   ifx_acc_id          = :sql_ifx_acc_id
      AND     ifx_usr_id          = uac_usr_id
      AND     uac_clm_mtch_accnt  = :c_mtch_accnt_no;

    if (SQLCODE != 0 )
    {
      fn_errlog( c_ServiceName, "S31080", SQLMSG, c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
     if (cnt_rec > 0)
    {
      st_usr_prfl.l_session_id=0;
    }
		else if (cnt_rec==0)
    {
      fn_errlog( c_ServiceName, "B31029",DEFMSG, c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      /*userlog("Value of SQLCODE after select :%d:",SQLCODE);*/
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
  }

  if( DEBUG_MSG_LVL_3 )  /*** Added in Ver 5.2 ***/ /*** ver 5.3, debug level changed from 1 to 0 ****/ /** Changes debug from 0 to 3  in Ver 7.6 **/
  {
		fn_userlog(c_ServiceName, "session id for order book <%ld><%s><%c><%s><%s>", st_usr_prfl.l_session_id,c_mtch_accnt_no,c_apisrc_flg,c_ven_nm,c_ven_id.arr); /*** Ver 6.4 API logs added ***/
  }

  /************ Ver 2.0 ends here **********/

	if (st_usr_prfl.l_session_id !=0)	 /*Ver 2.0 added for 	ifx*/
	{
		i_returncode = fn_chk_sssn( c_ServiceName, 
																&st_usr_prfl,
   	                           &st_err_msg ) ;

  	if ( i_returncode == -1 )
  	{
     	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, st_err_msg.c_err_msg, 0 );
     	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  	}
	}
	
	/***** Commented for Ver 4.2 ********
	i_returncode = Fvftos32( ptr_fml_ibuf,
                           (char *) &st_cntrct,
                           "vw_contract" );

  if ( i_returncode == -1 )
  {
    fn_errlog( c_ServiceName, "S31085", FMLMSG, c_errmsg  );
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }
	************* Ver 4.2 ********/

	strcpy ( ( char * )c_exchange_cd, st_cntrct.c_xchng_cd );
	strcpy ( ( char * )c_underlying, st_cntrct.c_undrlyng );
	strcpy ( ( char * )c_expiry_dt.arr, st_cntrct.c_expry_dt );
  SETLEN ( c_expiry_dt );
	strcpy ( c_pipe_id, st_usr_prfl.c_pipe_id);
	c_exercise_type  = st_cntrct.c_exrc_typ; 
	c_option_type    = st_cntrct.c_opt_typ; 
	li_strike_price  = st_cntrct.l_strike_prc;

	i_err[0] = Fget32( ptr_fml_ibuf, FFO_OPERATION_TYP, 0, (char *)&c_opr_typ, 0 );
  i_ferr [0] = Ferror32;

	if ( i_err[0] == -1 )
	{
		fn_errlog( c_ServiceName, "S31090", FMLMSG, c_errmsg  );
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
	}
  /*** Ver 4.7 Starts ***/
   i_err[0] = Fget32( ptr_fml_ibuf, FFO_DWL_FLG,0,(char *)&c_chk_new_site_flg,0);
    i_ferr [0] = Ferror32;

  if ( i_err[0] == -1 && i_ferr [0]!= FNOTPRES )
  {
    fn_errlog( c_ServiceName, "S31095", FMLMSG, c_errmsg  );
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
   fn_userlog(c_ServiceName," Flag for new Site ---------%c:", c_chk_new_site_flg);
  } 
 /*** 4.7 Ends ***/
  
  if( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/ /** ver 5.3, debug level changed from 1 to 0 ***/ /** Changes debug from 0 to 3 in Ver 7.6 **/
  {
  	fn_userlog(c_ServiceName," Flag for new Site ---------%c:", c_chk_new_site_flg);
		fn_userlog(c_ServiceName,"Order Book Operation Type Is :%c:",c_opr_typ);
  }

	if ( c_opr_typ == EXCHNG_ACK_AND_PIPE_ID_IP )
	{
		i_err[0] = 0;
		i_ferr[0] = 0;

		i_err[0] = Fget32( ptr_fml_ibuf, FFO_ACK_NMBR, 0,(char *)c_xchng_ack, 0 );
  	i_ferr [0] = Ferror32;

		if ( i_err[0] == -1 )
		{
			fn_errlog( c_ServiceName, "S31100", FMLMSG, c_errmsg  );
    	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
		}
	}

	MEMSET(c_ordr_ref);
  MEMSET(c_advisor_id);   /*** Ver 3.9 ***/
   
	i_err[1] = Fget32( ptr_fml_ibuf, FFO_ORDR_STTS, 0,
                                   (char *)&c_order_stts, 0 );
  i_ferr [1] = Ferror32;

	i_err[2] = Fget32( ptr_fml_ibuf, FFO_FROM_DT, 0,
                                   (char *)c_frm_dt.arr, 0 );
  i_ferr [2] = Ferror32;

	i_err[3] = Fget32( ptr_fml_ibuf, FFO_TO_DT, 0,
                                   (char *)c_to_dt.arr, 0 );
  i_ferr [3] = Ferror32;

	i_err[4] = Fget32( ptr_fml_ibuf, FFO_ORDR_RFRNC, 0,
																	(char *)c_ordr_ref.arr, 0 );   /** 2.7 **/

  i_ferr [4] = Ferror32;									/** 2.7 **/

  /*** Added for Ver 3.9 ***/
  i_err[5] = Fget32( ptr_fml_ibuf, FFO_USER_CODE, 0,
                                   (char *)c_advisor_id, 0 );
  i_ferr [5] = Ferror32;
  /*** End for Ver 3.9 ***/
  /*** Added for Ver 6.5 ***/ 
   i_err[6] = Fget32( ptr_fml_ibuf, FFO_EX_ORDR_TYP, 0,
                                    (char *)&c_sys_ordr_flg, 0 );
  i_ferr [6] = Ferror32;  
  /*** End for Ver 6.5 ***/
  for ( i_cnt = 1;  i_cnt <= 6; i_cnt++ )   /** Changed from 4 to 5 for Ver 3.9 **//** changed from                                                                                5 to 6 in Ver 6.5 **/  
	{
		if ( i_err[i_cnt] == -1 && i_ferr[i_cnt] != FNOTPRES )
		{
			fn_errlog( c_ServiceName, "S31105", Fstrerror32( i_ferr[i_cnt] ), 
								 c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
		}
		else if ( i_err[i_cnt] == -1 && i_ferr[i_cnt] == FNOTPRES )
		{
			switch ( i_cnt )
			{
				case 1:
					c_order_stts = '%';
					break;
				case 2:
				case 3:
					c_date_flag = 'N';
					break;
        case 5:                         /*** Added case 5 for Ver 3.9 ***/
          strcpy( c_advisor_id, "NA");
          break;
        case 6:
          c_sys_ordr_flg = 'N' ;         /** Added case for Ver 6.5 **/
          break;
			}
		}
	}


	SETLEN( c_frm_dt );
	SETLEN( c_to_dt );

	if( DEBUG_MSG_LVL_3 )           /** Ver 4.4 **/ /*** ver 5.3 , debug level changed from 1 to 0 ***/ /** Changes debug from 0 to 3 in Ver 7.6 **/
  {
    fn_userlog(c_ServiceName, " The From date is :%s: and To date is :%s:",c_frm_dt.arr,c_to_dt.arr);   /** Ver 4.4 **/
  }


  if( DEBUG_MSG_LVL_3 )           /** Ver 4.4 **/ /*** ver 5.3 , debug level changed from 1 to 0 ***/ /** Changes debug from 0 to 3 in Ver 7.6 **/
  {
    fn_userlog(c_ServiceName, " The sys order flag is  :%c:",c_sys_ordr_flg); 
     fn_userlog(c_ServiceName, " Order status flag is :%c:",c_order_stts);
     fn_userlog(c_ServiceName," advisor id is :%s:",c_advisor_id);
  }

 if( c_opr_typ != 'V' )  /*** VTC Order Log Ver 4.6 ***/
 {
	if ( c_date_flag == 'Y' )
	{
	/* Ver 1.4  Kaushik */

		EXEC SQL
       SELECT to_char(to_date(:c_frm_dt,'DD-MM-YYYY'),'DD-MON-YYYY'),
              to_char(to_date(:c_to_dt,'DD-MM-YYYY'),'DD-MON-YYYY')
       INTO   :c_frm_dt,
              :c_to_dt
       FROM   dual;

    if(SQLCODE != 0)
    {
      fn_errlog( c_ServiceName, "S31110", SQLMSG, c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
		SETNULL( c_frm_dt );
  	SETNULL( c_to_dt );

	 /* Ver 1.4  Kaushik Ends */

		if ( strcmp(c_exchange_cd,"NFO")	==	0	)
		{
			strcpy(c_min_pipe_id,"00");
			strcpy(c_max_pipe_id,"00");
		}
		else if ( strcmp(c_exchange_cd,"BFO")  ==  0 )
		{
			strcpy(c_min_pipe_id,"A0");
			strcpy(c_max_pipe_id,"A0");
		}
		else if ( strcmp(c_exchange_cd,"ALL")	==	0	)
		{
			 strcpy(c_min_pipe_id,"00");
 			 strcpy(c_max_pipe_id,"A0");
		}

		strcpy ( c_min_ref_num, (char *)fn_getref ( c_ServiceName, 
   		                                          c_frm_dt.arr, 
     		                                   /***     "00", 				Commented In Ver 2.8	***/
																								c_min_pipe_id,				/***	Ver	2.8	***/
       		                                      MIN,
         		                                    c_errmsg ) );
		strcpy ( c_max_ref_num, (char *)fn_getref ( c_ServiceName, 
   		                                          c_to_dt.arr, 
     		                                   /***     "00",         Commented In Ver 2.8  ***/ 
                                                c_max_pipe_id,        /***  Ver 2.8 ***/
       		                                      MAX,
         		                                    c_errmsg ) );
  }
  
	/*** Ver 2.8 Starts Here ****/

  if( DEBUG_MSG_LVL_3 )   /*** Ver 4.5 ***/
  {
    fn_userlog(c_ServiceName," c_exchange_cd  :%s:",c_exchange_cd);
       
  }

  if ( strcmp(c_exchange_cd,"ALL") == 0)
  {
  	memset(c_exchange_cd,'\0',sizeof(c_exchange_cd));
   	strcpy(c_exchange_cd,"%"); /*** commented in Ver 7.9 **/ /** Uncommented in ver 8.8 ***/
	/**	strcpy(c_exchange_cd,"NFO"); *** Ver 7.9 **/ /** commented in ver 8.8***/
   	rtrim(c_exchange_cd);
		if( DEBUG_MSG_LVL_3) /* Added debug level Ver 7.6 */  /*** change debug level 1 to 3 in ver 8.8 **/
		{
   		fn_userlog(c_ServiceName," c_exchange_cd  :%s:",c_exchange_cd);
		}
  }
  /*** Ver 2.8 Ends Here ****/

	if ( st_cntrct.c_prd_typ == ALL )
	{
		c_product_typ = '%';
		c_is_flg = '%';								/* 2.1 */
	}
	else
	{
		c_product_typ = st_cntrct.c_prd_typ;
	}

	if( c_product_typ == 'L' )			/* 2.1 new if condition */
	{
		c_is_flg = 'D';
		c_product_typ = '%';
	}

	if ( c_order_stts == ALL )
	{
		c_ordr_stts = '%';
	}
	else
	{
		c_ordr_stts = c_order_stts;
	}

	if( DEBUG_MSG_LVL_3 ) 
	{
		fn_userlog( c_ServiceName," IS FLG IS :%c:",c_is_flg );
		fn_userlog( c_ServiceName," PRODUCT TYPE IS :%c:", c_product_typ );
	}

	/*** Ver 2.6 starts here ***/

	MEMSET(c_cntrct_num); /** ver 4.1 **/

	/***	Ver 4.3 Starts	***/

	/***	Ver 4.3 Below Changes carried out for

	1] For days Today(strcmp fail): The record can exist only and only in current table. Hence We compare and ask system to check only in current table.
	2] For days Today + past(Strcmp success) : Record may exist in Current table or in History table. Hence we will query the History table as well.
	3] The Where Exist query on history table was taking much of the time...hence replaced with below logic.
	4] If below query fails then we are setting flag as 1 so that we can fetch data from both current and history table.

	*******************************************/

	MEMSET(c_ordbk_seq);
	MEMSET(c_nxt_trd_dt);
	MEMSET(c_nxt_trade_dt);            /** Ver 5.4 **/

	EXEC SQL
    SELECT TO_CHAR(EXG_NXT_TRD_DT,'YYYYMMDD')||LPAD(TO_CHAR(DECODE((LAST_NUMBER - 1),MAX_VALUE,0,(LAST_NUMBER - 1))),8,'0'),
           to_char(to_date(EXG_NXT_TRD_DT,'DD-Mon-YYYY'),'YYYYMMDD' ),
					 TO_CHAR(EXG_NXT_TRD_DT,'DD-Mon-YYYY')                  /** Ver 5.4 **/           
    INTO  :c_ordbk_seq,
          :c_nxt_trd_dt,
					:c_nxt_trade_dt                                         /** Ver 5.4 **/
    FROM  USER_SEQUENCES,EXG_XCHNG_MSTR
    WHERE SEQUENCE_NAME = 'DFO_DL_FO_ORDBK_SEQ'
    AND   EXG_XCHNG_CD  = 'NFO';

	if ( SQLCODE != 0 )
  {
		if( DEBUG_MSG_LVL_1) /* Added debug level Ver 7.6 */
		{
   		fn_userlog(c_ServiceName,"Failed to fetch Order Book Sequence No and Next Trade Date");
		}
   	li_rec_cnt_status_date = 1;   /*** Fetch records from both main table and history table ***/
  }
  else
  {
  	if( DEBUG_MSG_LVL_3 )  /*** ver 5.4 **** Debug level changed from 0 to 3 ***/
    {
    	fn_userlog(c_ServiceName,"Exchange Next Trade Date c_nxt_trd_dt Is :%s:.",c_nxt_trd_dt.arr);
      fn_userlog(c_ServiceName,"From Date Min Ref No Is :%s:",c_min_ref_num);
    }

    if (strncmp(c_min_ref_num,c_nxt_trd_dt.arr,8) < 0 )   /*** From Date is less than Next Trade Date ***/
    {
			if( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/
      { 
      	fn_userlog(c_ServiceName,"Inside History Fetch Counter Set.");
      }
 
    	li_rec_cnt_status_date = 1;     /*** Fetch records from both main table and history table ***/
    }
    else
    {
			if( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/
      {
      	fn_userlog(c_ServiceName,"Inside Current Fetch Counter Set.");
    	}

      li_rec_cnt_status_date = 0;     /*** Fetch records from main table only ***/
    }
  }

	/** Added for Ver 8.2 **/
	if(i_fpe_log_enblmnt_flag == 1)
	{
    fn_userlog(c_ServiceName, "c_user_id :%s: c_mtch_accnt_no :%s: From date :%s: To date :%s:,c_advisor_id :%s: c_ven_nm :%s: c_ven_id :%s:",st_usr_prfl.c_user_id,c_mtch_accnt_no,c_frm_dt.arr,c_to_dt.arr,c_advisor_id,c_ven_nm,c_ven_id.arr);
	}
	/** End for Ver 8.2 **/
  
  /** Added for Ver 7.8 **/
  /** if(li_rec_cnt_status_date == 1) ** Commented and changed for Ver 8.1 **/
  /** ver 8.7 nikhil start **/
  if (strcmp( st_usr_prfl.c_user_id, "system" )== 0  && st_usr_prfl.l_session_id == 0 )
  { /** ver 8.7 nikhil end **/

  if(i_trdngscrn_hstry_dsbl_flag == 1 && li_rec_cnt_status_date == 1)
  {
    fn_userlog( c_ServiceName,"Historical order book is not available at this time. Please try later.");
    strcpy(c_errmsg,"Historical order book is not available at this time. Please try later.");
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }
  }
  else
  {  /** ver 8.7 nikhil end **/
    if(i_fpe_hstry_dsbl_flag == 1 && li_rec_cnt_status_date == 1)   /** Condition changed for Ver 8.2 **/
    {
      fn_userlog( c_ServiceName,"Historical order book is not available at this time. Please try later.");
      strcpy(c_errmsg,"Historical order book is not available at this time. Please try later.");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
  } /** ver 8.7 nikhil end **/
  /** End for Ver 7.8 ** *** Commented in Ver 8.0 ***/

	SETNULL(c_ordbk_seq);
	SETNULL(c_nxt_trd_dt);
	SETNULL(c_nxt_trade_dt);           /** Ver 5.4 **/

	/*** Ver 4.3 Ends   ***/

	EXEC SQL ALLOCATE :sys_cursor;

	if ( c_date_flag == 'N' &&  c_opr_typ != ORDER_REF_IP )  /*** c_opr_typ condition added in Ver 5.0 ***/ 
	{
		fn_userlog( c_ServiceName,"From/To Dates are not Found in the Buffer" );
		Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
		tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
	}

	if(strcmp( c_mtch_accnt_no,"*")== 0)
  {
		if( DEBUG_MSG_LVL_3 ) 
		{
			fn_userlog(c_ServiceName,"Inside Match account is *   ");
		}

		strcpy ( c_user_id, st_usr_prfl.c_user_id);

  if(strcmp(c_advisor_id, "NA") == 0)         /*** Condition added for ver 3.9 ***/
  {
		if ( (st_usr_prfl.c_user_id[0] == BPID) )
		{
			if( DEBUG_MSG_LVL_3 ) 
			{
				fn_userlog(c_ServiceName,"DBC USER");
			}

			/***	Commented In Ver 4.3 

			li_rec_cnt_status_date = 0;
 
			EXEC SQL
				SELECT		1
				INTO		  :li_rec_cnt_status_date
				FROM			DUAL
				WHERE			EXISTS
				(
					SELECT	1
					FROM		FOD_FO_ORDR_DTLS_HSTRY,CLM_CLNT_MSTR
					WHERE	  FOD_CLM_MTCH_ACCNT =		CLM_MTCH_ACCNT 
					** AND			FOD_XCHNG_CD       =		:c_exchange_cd *** Ver 2.8 ***
          AND     FOD_XCHNG_CD       LIKE    :c_exchange_cd  *** Ver 2.8 ***
					AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
					*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                         CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 ***
         *** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ***** Ver 3.7 Include SLTP FuturePLUS orders *** 
					Commented in Ver 4.0 ***
					AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders **
					AND			FOD_ORDR_STTS      LIKE :c_ordr_stts 
					AND			FOD_IS_FLG         LIKE :c_is_flg		
					AND			CLM_BP_ID					 =		:c_user_id
					AND		
									( 
										( FOD_ORDR_RFRNC				>=  :c_min_ref_num 
											AND	  FOD_ORDR_RFRNC	<   :c_max_ref_num ) OR
										( FOD_ORDR_RFRNC				<		:c_min_ref_num 
											AND	FOD_ORDR_VALID_DT	>=	to_date(:c_frm_dt,'dd-mon-yyyy') )
									)
   		);

  		if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
			{		
				fn_errlog( c_ServiceName, "S31115", SQLMSG, c_errmsg  );
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
				tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}

			Ver 4.3 Comment Ends	***/
     
			if( DEBUG_MSG_LVL_3 )
 			{         
				fn_userlog(c_ServiceName,"li_rec_cnt_status_date [%ld]",li_rec_cnt_status_date);
				fn_userlog(c_ServiceName,"c_min_ref_num [%s]",c_min_ref_num);
				fn_userlog(c_ServiceName,"c_max_ref_num [%s]",c_max_ref_num); 
			}

      if ( li_rec_cnt_status_date != 1 )
			{

      /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM    FOD_FO_ORDR_DTLS,CLM_CLNT_MSTR
            WHERE   FOD_CLM_MTCH_ACCNT =    CLM_MTCH_ACCNT
            /** AND     FOD_XCHNG_CD       =    :c_exchange_cd ** Ver 2.8 ***/
            AND     FOD_XCHNG_CD LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     CLM_BP_ID           =   :c_user_id
            AND
                   (
                      ( FOD_ORDR_RFRNC        >=  :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <   :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <   :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') ));
            




      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31120", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
      	fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31125", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

     
				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                				NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM            /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     										FOD_EXPRY_DT,
     										FOD_EXER_TYP,
     										FOD_OPT_TYP,
     										FOD_STRK_PRC,
     										FOD_ORDR_FLW,
     										FOD_LMT_MRKT_SL_FLG,
     										FOD_DSCLSD_QTY,
     										FOD_ORDR_TOT_QTY,
     										FOD_LMT_RT,
     										FOD_STP_LSS_TGR,
     										FOD_ORDR_TYPE,
     										FOD_ORDR_VALID_DT,
     										FOD_TRD_DT,
     										FOD_ORDR_STTS,
     										FOD_EXEC_QTY,
     										FOD_CNCL_QTY,
     										FOD_EXPRD_QTY,
     										FOD_SPRD_ORDR_REF,
     										FOD_SETTLOR,
												FOD_MDFCTN_CNTR,
     										FOD_ACK_NMBR,
     										FOD_SPL_FLAG,
     										FOD_REMARKS,
     										FOD_CHANNEL,
     										FOD_BP_ID,
     										FOD_AMT_BLCKD,
     										FOD_FC_FLAG,
     										FOD_SPN_FLG,
     										FOD_TRD_VAL,
     										FOD_TRD_BRKG,
     										FOD_CNTRCTNT_NMBR,
     										FOD_SLTP_ORDR_RFRNC,
     										FOD_FC_FLAG1,
     										FOD_PRCIMPV_FLG,
     										FOD_ESP_ID,
     										FOD_SOURCE_FLG,
     										ROWNUM REC_INDEX,
												FXB_RQST_TM  /** Added in Ver 8.8 by Vishal **/
   FROM
   (
						SELECT	FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,  
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC, 
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,  
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,		/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,																/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,																/*** Ver 3.2 ***/
										NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,																	/*** Ver 4.1 ***/
									  NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              	/*** Ver 4.3 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,													/*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                        /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,													/*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,                                /*** Ver 6.4 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM                               /** Added in Ver 8.8 by Vishal */       
						FROM		FOD_FO_ORDR_DTLS,CLM_CLNT_MSTR,FXB_FO_XCHNG_BOOK  /** Added in Ver 8.8 by Vishal */		
						WHERE		FOD_CLM_MTCH_ACCNT =		CLM_MTCH_ACCNT	 
						/** AND			FOD_XCHNG_CD       =		:c_exchange_cd ** Ver 2.8 ***/
            AND   	FOD_XCHNG_CD  LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
						AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
						/*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                           CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 **/
            /*** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ***** Ver 3.7 Include SLTP FuturePLUS orders ***
						Commented in Ver 4.0 ***/
						/*** AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3 ***/
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND 		FOD_ORDR_STTS			 <>		'Y'	
						AND			FOD_IS_FLG				 LIKE	:c_is_flg 
						AND			CLM_BP_ID					 	=		:c_user_id 			
      			AND		
									 (  
											( FOD_ORDR_RFRNC			  >=  :c_min_ref_num 
												AND	  FOD_ORDR_RFRNC  <   :c_max_ref_num ) OR
											( FOD_ORDR_RFRNC				<		:c_min_ref_num 
												AND	FOD_TRD_DT >=	to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
										)
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
						/* ORDER BY	FOD_CLM_MTCH_ACCNT,FOD_ORDR_RFRNC DESC */  /**Commented in Ver 8.8 **/
						ORDER BY  FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 by Vishal **/
					)
					),FTQ_FO_TRD_QT
  					WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
				AND decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP)= FTQ_PRDCT_TYP(+)
 					  AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
  				  AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
 					  AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
  				  AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
  				  AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
          AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC ,FOD_ORDR_RFRNC DESC;  /** Added in Ver 8.8 by Vishal **/  
					END;
				END-EXEC;
			}

			else if ( li_rec_cnt_status_date == 1 )
			{


       /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
            FROM
     (
          SELECT FOD_ORDR_RFRNC
          FROM    FOD_FO_ORDR_DTLS,CLM_CLNT_MSTR
            WHERE   FOD_CLM_MTCH_ACCNT = CLM_MTCH_ACCNT
            AND     FOD_XCHNG_CD  LIKE  :c_exchange_cd  /*** Ver 2.8 ***/  /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     CLM_BP_ID          =    :c_user_id
            AND
                    (
                      ( FOD_ORDR_RFRNC        >= :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <  :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <  :c_min_ref_num
                        /*** AND  FOD_ORDR_VALID_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') ) ** Commented in Ver 4.6 **/
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') ) 
										) 
            UNION ALL
      select FOD_ORDR_RFRNC
      FROM  FOD_FO_ORDR_DTLS_HSTRY,CLM_CLNT_MSTR
            WHERE FOD_CLM_MTCH_ACCNT = CLM_MTCH_ACCNT
            AND FOD_XCHNG_CD   LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND   FOD_PRDCT_TYP      LIKE :c_product_typ
            AND   FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND   FOD_ORDR_STTS      <>   'Y'
            AND   FOD_IS_FLG         LIKE :c_is_flg
            AND   CLM_BP_ID          =    :c_user_id
            AND
                  (
                    ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                      AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                    (FOD_ORDR_RFRNC         <     :c_min_ref_num
                      AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )));  


      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31130", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

 		  if(l_tot_pages == 0) {
    	  l_tot_pages = 1;
      	}

 		  if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31135", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
						SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM    /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
		 FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,
     FOD_FC_FLAG,
     FOD_SPN_FLG,
     FOD_TRD_VAL,
     FOD_TRD_BRKG,
     FOD_CNTRCTNT_NMBR,
     FOD_SLTP_ORDR_RFRNC,
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,
     FOD_ESP_ID,
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
	  FXB_RQST_TM    /** Added in Ver 8.8 by Vishal **/
   FROM
   (
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY , 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
										NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM                    /** Added in Ver 8.8 by Vishal **/
						FROM		FOD_FO_ORDR_DTLS,CLM_CLNT_MSTR,FXB_FO_XCHNG_BOOK  /** FXB_FO_XCHNG_BOOK added in Ver 8.8 */
						WHERE		FOD_CLM_MTCH_ACCNT = CLM_MTCH_ACCNT
					/***	AND			FOD_XCHNG_CD       =	  :c_exchange_cd ** Ver 2.8 ***/
            AND  		FOD_XCHNG_CD LIKE :c_exchange_cd  /*** Ver 2.8 ***/  /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
						AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
						/*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                           CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7  ***/
            /*** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ** *** Ver 3.7 SLTP FuturePLUS orders included ***
						Commented in Ver 4.0 ***/
          	/*** AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3 ***/
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND 		FOD_ORDR_STTS			 <>		'Y'	
						AND			FOD_IS_FLG				 LIKE	:c_is_flg
			  	  AND			CLM_BP_ID					 =		:c_user_id 			
          	AND		
										(
											( FOD_ORDR_RFRNC				>= :c_min_ref_num 
												AND	  FOD_ORDR_RFRNC	<  :c_max_ref_num ) OR
											( FOD_ORDR_RFRNC				<	 :c_min_ref_num 
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                    )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC  /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
            UNION ALL

						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_LMT_RT, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_REMARKS,  
										NVL( FOD_BP_ID,' ')  FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																/*** Ver 6.4 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM                     /** Added in Ver 8.8 by Vishal **/
						FROM  FOD_FO_ORDR_DTLS_HSTRY,CLM_CLNT_MSTR,FXB_FO_XCHNG_BOOK_HSTRY /* FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/
						WHERE FOD_CLM_MTCH_ACCNT = CLM_MTCH_ACCNT
					/***	AND		FOD_XCHNG_CD       =		:c_exchange_cd *** Ver 2.8 ***/
            AND FOD_XCHNG_CD    LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8 **/
						AND	  FOD_PRDCT_TYP			 LIKE :c_product_typ
						/*** AND    FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                         CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F + orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 **/
            /*** AND   FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ** *** Ver 3.7 ***
						Commented in Ver 4.0 ***/
        /***AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3 ***/
						AND	  FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND 	FOD_ORDR_STTS			 <>		'Y'	
						AND   FOD_IS_FLG				 LIKE :c_is_flg 
						AND   CLM_BP_ID					 =		:c_user_id		
        		AND		
									(  
										( FOD_ORDR_RFRNC				>=    :c_min_ref_num 
											AND	  FOD_ORDR_RFRNC	<     :c_max_ref_num ) OR
										(FOD_ORDR_RFRNC					<			:c_min_ref_num 
                      AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
									)
					AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC  /** Added in Ver 8.8 by Vishal **/
          AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
          /** ORDER BY 1,2 DESC **/   /** Commented in Ver 8.8 **/
					ORDER BY  FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 by Vishal **/
          )
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP)= FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
				  AND    REC_INDEX <=:l_end_rec_no
					ORDER BY  FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC ,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 by Vishal **/ 

        END;
				END-EXEC;
			}
		} 
		
		else
		{
			if( DEBUG_MSG_LVL_3 ) 
			{
				fn_userlog(c_ServiceName,"NON DBC USER");
			}

			/***	Commented In Ver 4.3

			li_rec_cnt_status_date = 0;
	
			EXEC SQL
			SELECT		1
			INTO		:li_rec_cnt_status_date
			FROM			dual
			WHERE			EXISTS
			(
				SELECT		1
				FROM	FOD_FO_ORDR_DTLS_HSTRY,UAC_USR_ACCNTS
				WHERE	FOD_CLM_MTCH_ACCNT = UAC_CLM_MTCH_ACCNT 
				*** AND	  FOD_XCHNG_CD       = :c_exchange_cd *** Ver 2.8 ***
        AND    FOD_XCHNG_CD   LIKE :c_exchange_cd *** Ver 2.8 ***
				AND	  FOD_PRDCT_TYP   LIKE :c_product_typ
				*** AND    FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                         	 CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F + orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 **
       *** AND   FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ** *** Ver 3.7 ***
				Commented in Ver 4.0 ***
        AND   FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders **
				AND	  FOD_ORDR_STTS   LIKE :c_ordr_stts 
				AND   FOD_IS_FLG      LIKE :c_is_flg				
				AND   UAC_USR_ID				 = :c_user_id 
				AND		
							( 
								( FOD_ORDR_RFRNC					>=  :c_min_ref_num 
									AND	  FOD_ORDR_RFRNC		<   :c_max_ref_num ) OR
								(	FOD_ORDR_RFRNC					<		:c_min_ref_num 
									AND	FOD_ORDR_VALID_DT		>=	to_date(:c_frm_dt,'dd-mon-yyyy') )
							)
			);

	  	if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
			{	
				fn_errlog( c_ServiceName, "S31140", SQLMSG, c_errmsg  );
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
				tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}

			Ver 4.3 Comment Ends	**********/

			if( DEBUG_MSG_LVL_3 ) 
			{          
				fn_userlog(c_ServiceName,"li_rec_cnt_status_date [%ld]",li_rec_cnt_status_date);
				fn_userlog(c_ServiceName,"c_min_ref_num [%s]",c_min_ref_num);
				fn_userlog(c_ServiceName,"c_max_ref_num [%s]",c_max_ref_num); 
			}

 	 		if ( li_rec_cnt_status_date != 1 )
			{

       /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM    FOD_FO_ORDR_DTLS,UAC_USR_ACCNTS
            WHERE   FOD_CLM_MTCH_ACCNT =    UAC_CLM_MTCH_ACCNT
            /*** AND      FOD_XCHNG_CD       =    :c_exchange_cd *** Ver 2.8 ***/
            AND      FOD_XCHNG_CD   LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8**/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            /*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                           CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )*** Ver 3.1 to exclude SLTP F+ orders
 from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 **/
            /*** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+
orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ** *** Ver 3.7 SLTP FuturePLUS orders included ***
            Commented in Ver 4.0 ***/
         /**AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3 ***/
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     UAC_USR_ID         =    :c_user_id
            AND
                    (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      (FOD_ORDR_RFRNC         < :c_min_ref_num
                        /** AND FOD_ORDR_VALID_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') ) ** Commented in ver 4.6 **/
                       AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                    );
                     



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31145", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

 		  if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31150", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/
    


				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM                     /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM         /** Added in Ver 8.8 by Vishal **/
   FROM
   (
						SELECT	FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC, 
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                    
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                     FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,							/*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM  FXB_RQST_TM        /** Added in Ver 8.8 by Vishal **/
						FROM		FOD_FO_ORDR_DTLS,UAC_USR_ACCNTS,FXB_FO_XCHNG_BOOK /** Added in Ver 8.8 by Vishal **/		
						WHERE		FOD_CLM_MTCH_ACCNT =		UAC_CLM_MTCH_ACCNT	
						/*** AND			FOD_XCHNG_CD       =		:c_exchange_cd *** Ver 2.8 ***/
            AND      FOD_XCHNG_CD  LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
						AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
						/*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                           CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )*** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 **/
            /*** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ** *** Ver 3.7 SLTP FuturePLUS orders included ***
						Commented in Ver 4.0 ***/
         /**AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3 ***/
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND 		FOD_ORDR_STTS			 <>		'Y'										
						AND			FOD_IS_FLG				 LIKE :c_is_flg             
						AND			UAC_USR_ID				 =		:c_user_id
  					AND		
										(  
											( FOD_ORDR_RFRNC				>=    :c_min_ref_num 
												AND	  FOD_ORDR_RFRNC	<     :c_max_ref_num ) OR
											(FOD_ORDR_RFRNC					< :c_min_ref_num 
                       AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
				     				)
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR	/** Added in Ver 8.8 by Vishal **/
          /* ORDER BY FOD_CLM_MTCH_ACCNT, FOD_ORDR_RFRNC DESC **/ /** Commented in Ver 8.8 **/
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC ,FOD_ORDR_RFRNC DESC  /** Added in Ver 8.8 by Vishal **/
					)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP)= FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
				  AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC;  /** Added in Ver 8.8 by Vishal **/ 
	
        END;
				END-EXEC;
		   }
		
			 else if ( li_rec_cnt_status_date == 1 ) 
			 {

        /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
            FROM
     (
          SELECT FOD_ORDR_RFRNC
          FROM    FOD_FO_ORDR_DTLS,UAC_USR_ACCNTS
              WHERE   FOD_CLM_MTCH_ACCNT =    UAC_CLM_MTCH_ACCNT
              AND      FOD_XCHNG_CD   LIKE :c_exchange_cd   /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
              AND     FOD_PRDCT_TYP      LIKE :c_product_typ
              AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
              AND     FOD_ORDR_STTS      <>   'Y'
              AND     FOD_IS_FLG         LIKE :c_is_flg
              AND     UAC_USR_ID         =    :c_user_id
              AND
                    (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
										)
              UNION ALL
      select FOD_ORDR_RFRNC
      FROM     FOD_FO_ORDR_DTLS_HSTRY,UAC_USR_ACCNTS
             WHERE    FOD_CLM_MTCH_ACCNT = UAC_CLM_MTCH_ACCNT
             AND      FOD_XCHNG_CD    LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND      UAC_USR_ID = :c_user_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') ))  /*** ver 4.6 ***/
                 ); 

      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31155", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31160", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


					EXEC SQL	EXECUTE
						BEGIN
							OPEN	:sys_cursor	FOR
    					SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM                /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
     FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM          /** Added in Ver 8.8 by Vishal **/
   FROM
   (
							SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
											FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
											FOD_PIPE_ID FOD_PIPE_ID, 
											FOD_XCHNG_CD FOD_XCHNG_CD, 
											FOD_PRDCT_TYP FOD_PRDCT_TYP,
											FOD_INDSTK FOD_INDSTK,
											FOD_UNDRLYNG FOD_UNDRLYNG, 
											to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
											FOD_EXER_TYP FOD_EXER_TYP, 
											FOD_OPT_TYP FOD_OPT_TYP, 
											FOD_STRK_PRC FOD_STRK_PRC,
											FOD_ORDR_FLW FOD_ORDR_FLW, 
											FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
											NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
											FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
											NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
											NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
											FOD_ORDR_TYPE FOD_ORDR_TYPE, 
											to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
											to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' )  FOD_TRD_DT, 
											FOD_ORDR_STTS FOD_ORDR_STTS,
											FOD_EXEC_QTY FOD_EXEC_QTY, 
											FOD_CNCL_QTY FOD_CNCL_QTY, 
											FOD_EXPRD_QTY FOD_EXPRD_QTY, 
											NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
											NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
											FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
											NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
											FOD_SPL_FLAG FOD_SPL_FLAG,
											NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
											NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                    
											NVL( FOD_BP_ID,' ') FOD_BP_ID,
											NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
											NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
											NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    	NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    	NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    	NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                      FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                      FOD_FC_FLAG FOD_FC_FLAG1 ,                                         /*** Ver 4.7 ***/
										  NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
											NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																 /*** Ver 6.4 ***/
											NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/	
                      NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
											FXB_RQST_TM FXB_RQST_TM          /** Added in Ver 8.8 by Vishal **/
							FROM		FOD_FO_ORDR_DTLS,UAC_USR_ACCNTS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 */
							WHERE		FOD_CLM_MTCH_ACCNT =		UAC_CLM_MTCH_ACCNT
							/*** AND			FOD_XCHNG_CD       =		:c_exchange_cd *** Ver 2.8 ***/
              AND      FOD_XCHNG_CD  LIKE  :c_exchange_cd   /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
							AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
							/*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                             CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 **/
              /*** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ** *** Ver 3.7 SLTP FuturePLUS orders included ***
							Commented in Ver 4.0 ***/
         /*** AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3 ***/
							AND			FOD_ORDR_STTS      LIKE :c_ordr_stts 
							AND 		FOD_ORDR_STTS		   <>		'Y'										
							AND			FOD_IS_FLG         LIKE :c_is_flg              
							AND			UAC_USR_ID				 =    :c_user_id
  						AND		
										(
											( FOD_ORDR_RFRNC				>=    :c_min_ref_num 
												AND	  FOD_ORDR_RFRNC	<     :c_max_ref_num ) OR
											( FOD_ORDR_RFRNC				<			:c_min_ref_num 
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
										)			
							AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
              AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
							UNION ALL
			
							SELECT	FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
											FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
											FOD_PIPE_ID FOD_PIPE_ID, 
											FOD_XCHNG_CD FOD_XCHNG_CD, 
											FOD_PRDCT_TYP FOD_PRDCT_TYP,
											FOD_INDSTK FOD_INDSTK,
											FOD_UNDRLYNG FOD_UNDRLYNG, 
											to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
											FOD_EXER_TYP FOD_EXER_TYP, 
											FOD_OPT_TYP FOD_OPT_TYP, 
											FOD_STRK_PRC FOD_STRK_PRC,
											FOD_ORDR_FLW FOD_ORDR_FLW, 
											FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
											NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
											FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
											NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
											NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
											FOD_ORDR_TYPE  FOD_ORDR_TYPE, 
											to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
											to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
											FOD_ORDR_STTS FOD_ORDR_STTS,
											FOD_EXEC_QTY FOD_EXEC_QTY, 
											FOD_CNCL_QTY FOD_CNCL_QTY, 
											FOD_EXPRD_QTY FOD_EXPRD_QTY, 
											NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
											NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
											FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
											NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
											FOD_SPL_FLAG FOD_SPL_FLAG,
											NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
											NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                    
											NVL( FOD_BP_ID,' ') FOD_BP_ID,
											NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
											NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
											NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    	NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    	NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    	NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                      FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                      FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
											NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
											NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
											 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                      NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
											FXB_RQST_TM FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
						 FROM			FOD_FO_ORDR_DTLS_HSTRY,UAC_USR_ACCNTS,FXB_FO_XCHNG_BOOK_HSTRY  /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/
						 WHERE		FOD_CLM_MTCH_ACCNT = UAC_CLM_MTCH_ACCNT
						 /***  AND			FOD_XCHNG_CD       = :c_exchange_cd ** Ver 2.8 ***/
             AND      FOD_XCHNG_CD  LIKE   :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
						 AND			FOD_PRDCT_TYP   LIKE :c_product_typ
						 /*** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'U' ELSE 'Z' END,
                                             CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites Commented In Ver 3.7 **/
             /*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END ) *** Ver 3.1 to exclude SLTP F+ orders from other sites *** ** Ver 3.6 to exclude Option+ orders from other sites ** *** Ver 3.7 SLTP FutuePLUS orders included ***
						 Commented in Ver 4.0 ***/
         /***AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3	***/
						 AND			FOD_ORDR_STTS   LIKE :c_ordr_stts 
						 AND			FOD_ORDR_STTS		<> 'Y'											
						 AND			FOD_IS_FLG      LIKE :c_is_flg             
						 AND			UAC_USR_ID = :c_user_id
      			 AND				
										 (  
											( FOD_ORDR_RFRNC				>=    :c_min_ref_num 
												AND	  FOD_ORDR_RFRNC	<     :c_max_ref_num ) OR
											( FOD_ORDR_RFRNC				<			:c_min_ref_num 
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
										 )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
            /** ORDER BY 1,2 DESC **/  /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC ,FOD_ORDR_RFRNC DESC  /** Added in Ver 8.8 by Vishal **/
						)
						),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
				    AND    REC_INDEX <=:l_end_rec_no 
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC;  /** Added in Ver 8.8 by Vishal **/	
          END;
					END-EXEC;
			 }
		}
	 }
  /*** Added for Ver 3.9 ***/
   else if(strcmp(c_advisor_id, "NA") != 0)
   {

    /** li_rec_cnt_adv = 0;     **** Ver 3.9 changed on 12-Jan-2015 **/

		/*** Added for 3.9 25-Jan-2015 ***/
    EXEC SQL
      SELECT 1
      INTO :li_rec_cnt_adv
      FROM DUAL
      WHERE
        trunc(SYSDATE) <> to_date(:c_frm_dt,'DD-MON-YYYY');

   if(( SQLCODE != 0) && ( SQLCODE != NO_DATA_FOUND ))
   {
      fn_errlog( c_ServiceName, "S31165", SQLMSG, c_errmsg  );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpcommit(0);      /***  Ver 1.9 ***/
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
   }
   /*** Added for 3.9 25-Jan-2015 ***/

    if( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/
    {
   		fn_userlog(c_ServiceName,"li_rec_cnt_adv [%ld]",li_rec_cnt_adv);
    }

    if(c_opr_typ == STATUS_PRODUCT_AND_DATE_IP)
    {
			if( DEBUG_MSG_LVL_3 ) /** Changes debug from 0 to 3 in Ver 7.6 **/
      {
        fn_userlog(c_ServiceName,"Inside Advisor without Underlying");
      }

      if( DEBUG_MSG_LVL_3 )
      {
        fn_userlog(c_ServiceName,"li_rec_cnt_status_date [%ld]",li_rec_cnt_adv);
        fn_userlog(c_ServiceName,"c_min_ref_num [%s]",c_min_ref_num);
        fn_userlog(c_ServiceName,"c_max_ref_num [%s]",c_max_ref_num);
        fn_userlog(c_ServiceName, " The sys order flag is  :%c:",c_sys_ordr_flg); 
      }

      if ( li_rec_cnt_adv != 1 ) 
      {
  
      /*** Ver 6.5 Starts ***/     

       if ( c_sys_ordr_flg == 'S' )          /****** if-else Added for Ver 6.5 *****/
         {

         /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM    FOD_FO_ORDR_DTLS,ACM_ADV_CLNT_MAP
            WHERE   FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT
            AND     FOD_XCHNG_CD   LIKE :c_exchange_cd  /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP     LIKE :c_product_typ
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     ACM_ACTV_FLG       = 'A'
            AND     ACM_ADVISOR_ID     = :c_advisor_id
            AND     FOD_CHANNEL        = 'SYS'
            AND
                    (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      (FOD_ORDR_RFRNC         < :c_min_ref_num
                       AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )
                    );
                     



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31170", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 nikhil Ends here ***/
 
      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }


   		if(l_page_no < 1)
 		  {
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
     	 	fn_errlog( c_ServiceName, "S31175", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

 
          EXEC SQL  EXECUTE
          BEGIN
            OPEN  :sys_cursor FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM               /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM         /** Added in Ver 8.8 by Vishal **/
   FROM
   (
            SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                    FOD_PIPE_ID FOD_PIPE_ID,
                    FOD_XCHNG_CD FOD_XCHNG_CD,
                    FOD_PRDCT_TYP FOD_PRDCT_TYP,
                    FOD_INDSTK FOD_INDSTK,
                    FOD_UNDRLYNG FOD_UNDRLYNG,
                    to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                    FOD_EXER_TYP FOD_EXER_TYP,
                    FOD_OPT_TYP FOD_OPT_TYP,
                    FOD_STRK_PRC FOD_STRK_PRC,
                    FOD_ORDR_FLW FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                    NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                    FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                    NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                    NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                    FOD_ORDR_TYPE FOD_ORDR_TYPE,
                    to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                    to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                    FOD_ORDR_STTS FOD_ORDR_STTS,
                    FOD_EXEC_QTY FOD_EXEC_QTY,
                    FOD_CNCL_QTY FOD_CNCL_QTY,
                    FOD_EXPRD_QTY FOD_EXPRD_QTY,
                    NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                    NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                    FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                    NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                    FOD_SPL_FLAG FOD_SPL_FLAG,
                    NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                    NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                    NVL( FOD_BP_ID,' ') FOD_BP_ID,
                    NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,
                    NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,
                    NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,                               
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                                 
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                        
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                         
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                            
                    FOD_FC_FLAG FOD_FC_FLAG1,                                        
                    NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                         
                    NVL(FOD_ESP_ID,'*') FOD_ESP_ID,
				 		 			 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/   
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                            /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/            
            FROM    FOD_FO_ORDR_DTLS,ACM_ADV_CLNT_MAP,FXB_FO_XCHNG_BOOK /* FXB_FO_XCHNG_BOOK added in Ver 8.8 */     
            WHERE   FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT
            AND     FOD_XCHNG_CD     LIKE  :c_exchange_cd  /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP     LIKE :c_product_typ
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     ACM_ACTV_FLG       = 'A'             
            AND     ACM_ADVISOR_ID     = :c_advisor_id   
            AND     FOD_CHANNEL        = 'SYS'           
            AND
                    (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      (FOD_ORDR_RFRNC         < :c_min_ref_num
                       AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  
                    )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
          /** ORDER BY FOD_CLM_MTCH_ACCNT, FOD_ORDR_RFRNC DESC **/  /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 by Vishal **/
 					)
          ),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
       AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 by Vishal **/		 
 
        END;
        END-EXEC;
       } 
       else   /*** Ver 6.5 Ends ***/ 
       {

            /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM    FOD_FO_ORDR_DTLS,CNT_CSE_MAST
            WHERE   FOD_XCHNG_CD       LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     FOD_CSE_ID = CCM_CSE_ID
            AND     CCM_LOGIN_NAME = :c_advisor_id
            AND
                    (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      (FOD_ORDR_RFRNC         < :c_min_ref_num
                        /** AND FOD_ORDR_VALID_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') ) ** Ver 4.6 **/
                       AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                    );
                     



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31180", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31185", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


      /*** ver 8.4 nikhil Ends here ***/


            EXEC SQL  EXECUTE
            BEGIN
            OPEN  :sys_cursor FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM             /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM     /** Added in Ver 8.8 by Vishal **/
   FROM
   (
            SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                    FOD_PIPE_ID FOD_PIPE_ID,
                    FOD_XCHNG_CD FOD_XCHNG_CD,
                    FOD_PRDCT_TYP FOD_PRDCT_TYP,
                    FOD_INDSTK FOD_INDSTK,
                    FOD_UNDRLYNG FOD_UNDRLYNG,
                    to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                    FOD_EXER_TYP FOD_EXER_TYP,
                    FOD_OPT_TYP FOD_OPT_TYP,
                    FOD_STRK_PRC FOD_STRK_PRC,
                    FOD_ORDR_FLW FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                    NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                    FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                    NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                    NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                    FOD_ORDR_TYPE FOD_ORDR_TYPE,
                    to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                    to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                    FOD_ORDR_STTS FOD_ORDR_STTS,
                    FOD_EXEC_QTY FOD_EXEC_QTY,
                    FOD_CNCL_QTY FOD_CNCL_QTY,
                    FOD_EXPRD_QTY FOD_EXPRD_QTY,
                    NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                    NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                    FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                    NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                    FOD_SPL_FLAG FOD_SPL_FLAG,
                    NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                    NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                    NVL( FOD_BP_ID,' ') FOD_BP_ID,
                    NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,
                    NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,
                    NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                                 /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                                /*** Ver 4.1 ***/					
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                          /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM       /** Added in Ver 8.8 by Vishal **/
            FROM    FOD_FO_ORDR_DTLS,CNT_CSE_MAST,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 */
            WHERE   FOD_XCHNG_CD  LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            /*** AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
						Commented in Ver 4.0 ***/
        /***AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3	***/
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
      			AND 		FOD_CSE_ID = CCM_CSE_ID
            AND 		CCM_LOGIN_NAME = :c_advisor_id
            AND
                    (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      (FOD_ORDR_RFRNC         < :c_min_ref_num
                       AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
               )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/    
          /** ORDER BY FOD_CLM_MTCH_ACCNT, FOD_ORDR_RFRNC DESC **/ /**Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
					)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
       AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC ,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
 
        END;
        END-EXEC;
       }
     }
   
       else if ( li_rec_cnt_adv == 1 )
 
       {
         /*** Ver 6.5 Starts ***/ 
          if ( c_sys_ordr_flg == 'S' )                        /*** if-els added in Ver 6.5 ***/
            {
		   
							if(DEBUG_MSG_LVL_1) /* Added debug level Ver 7.6 */
							{
            		fn_userlog(c_ServiceName, " inside query for fod history"); 
							}
                    

           /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM     FOD_FO_ORDR_DTLS_HSTRY,ACM_ADV_CLNT_MAP
             WHERE    FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT
             AND      FOD_XCHNG_CD  LIKE  :c_exchange_cd /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND      FOD_CHANNEL     = 'SYS'
             AND      ACM_ACTV_FLG    = 'A'
             AND      FOD_TRD_DT      =  to_date(:c_frm_dt,'dd-mon-yyyy')
             AND      ACM_ADVISOR_ID  = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )
                    ); 



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31190", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31195", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

 
            EXEC SQL  EXECUTE
            BEGIN
            OPEN      :sys_cursor FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM           /** Added in Ver 8.8 by Vishal **/
   FROM
   (
            SELECT    FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                      FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                      FOD_PIPE_ID FOD_PIPE_ID,
                      FOD_XCHNG_CD FOD_XCHNG_CD,
                      FOD_PRDCT_TYP FOD_PRDCT_TYP,
                      FOD_INDSTK FOD_INDSTK,
                      FOD_UNDRLYNG FOD_UNDRLYNG,
                      to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                      FOD_EXER_TYP FOD_EXER_TYP,
                      FOD_OPT_TYP FOD_OPT_TYP,
                      FOD_STRK_PRC FOD_STRK_PRC,
                      FOD_ORDR_FLW FOD_ORDR_FLW,
                      FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                      NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                      FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                      NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                      NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                      FOD_ORDR_TYPE FOD_ORDR_TYPE,
                      to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                      to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                      FOD_ORDR_STTS FOD_ORDR_STTS,
                      FOD_EXEC_QTY FOD_EXEC_QTY,
                      FOD_CNCL_QTY FOD_CNCL_QTY,
                      FOD_EXPRD_QTY FOD_EXPRD_QTY,
                      NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                      NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                      FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                      NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                      FOD_SPL_FLAG FOD_SPL_FLAG,
                      NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                      NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                      NVL( FOD_BP_ID,' ') FOD_BP_ID,
                      NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,  
                      NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,                             
                      NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,                            
                      NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                             
                      NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                           
                      NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                   
                      FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                         
                      FOD_FC_FLAG FOD_FC_FLAG1,                                
                      NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                
                      NVL(FOD_ESP_ID,'*') FOD_ESP_ID,
											NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/ 
                      NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
											FXB_RQST_TM  FXB_RQST_TM                     /** Added in Ver 8.8 by Vishal **/           
             FROM     FOD_FO_ORDR_DTLS_HSTRY,ACM_ADV_CLNT_MAP,FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/  
             WHERE    FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT 
             AND      FOD_XCHNG_CD   LIKE  :c_exchange_cd /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND      FOD_CHANNEL     = 'SYS'                     
             AND      ACM_ACTV_FLG    = 'A'                      
             AND      FOD_TRD_DT      =  to_date(:c_frm_dt,'dd-mon-yyyy') 
             AND      ACM_ADVISOR_ID  = :c_advisor_id               
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  
                   ) 
	          AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC  /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/					 
            /** ORDER BY 1,2 DESC **/  /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/ 
  				)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
        AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
 
          END;
          END-EXEC;
           }
       else    /***Ver 6.5 Ends ***/
           {

            /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM     FOD_FO_ORDR_DTLS_HSTRY,CNT_CSE_MAST
             WHERE    FOD_XCHNG_CD    LIKE  :c_exchange_cd /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND FOD_CSE_ID = CCM_CSE_ID
             AND FOD_TRD_DT = to_date(:c_frm_dt,'dd-mon-yyyy') /** Added for 3.9 on 04-May-2015 **/
             AND CCM_LOGIN_NAME = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        /** AND FOD_ORDR_VALID_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') ) ** Ver 4.6 **/
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     );
                     



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31200", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

 	  	if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31205", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


            EXEC SQL  EXECUTE
            BEGIN
            OPEN      :sys_cursor FOR
         /***     SELECT  FOD_CLM_MTCH_ACCNT,
                      FOD_ORDR_RFRNC,
                      FOD_PIPE_ID,
                      FOD_XCHNG_CD,
                      FOD_PRDCT_TYP,
                      FOD_INDSTK,
                      FOD_UNDRLYNG,
                      to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ),
                      FOD_EXER_TYP,
                      FOD_OPT_TYP,
                      FOD_STRK_PRC,
                      FOD_ORDR_FLW,
                      FOD_LMT_MRKT_SL_FLG,
                      NVL( FOD_DSCLSD_QTY, 0 ),
                      FOD_ORDR_TOT_QTY,
                      NVL( FOD_LMT_RT, 0 ),
                      NVL( FOD_STP_LSS_TGR, 0 ),
                      FOD_ORDR_TYPE,
                      to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ),
                      to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ),
                      FOD_ORDR_STTS,
                      FOD_EXEC_QTY,
                      FOD_CNCL_QTY,
                      FOD_EXPRD_QTY,
                      NVL( FOD_SPRD_ORDR_REF, ' ' ),
                      NVL( FOD_SETTLOR, ' ' ),
                      FOD_MDFCTN_CNTR,
                      NVL( FOD_ACK_NMBR, ' ' ),
                      FOD_SPL_FLAG,
                      NVL( FOD_REMARKS, ' ' ),
                      NVL( FOD_CHANNEL,'*'),
                      NVL( FOD_BP_ID,' '),
                      NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0),
                      NVL(FOD_FC_FLAG,' '),
                      NVL(FOD_SPN_FLG,'N')
              FROM    FOD_FO_ORDR_DTLS,CNT_CSE_MAST
              WHERE   FOD_XCHNG_CD      LIKE :c_exchange_cd  *LIKE added in Ver 8.8* 
              AND     FOD_PRDCT_TYP      LIKE :c_product_typ
              AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
              AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
              AND     FOD_ORDR_STTS      <>   'Y'
              AND     FOD_IS_FLG         LIKE :c_is_flg
        AND FOD_CSE_ID = CCM_CSE_ID
              AND CCM_LOGIN_NAME = :c_advisor_id
              AND
                    (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_ORDR_VALID_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') )
                    )
              UNION ALL******** Commented for only history view ***/

              SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM       /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (
              SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                      FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                      FOD_PIPE_ID FOD_PIPE_ID,
                      FOD_XCHNG_CD FOD_XCHNG_CD,
                      FOD_PRDCT_TYP FOD_PRDCT_TYP,
                      FOD_INDSTK FOD_INDSTK,
                      FOD_UNDRLYNG FOD_UNDRLYNG,
                      to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                      FOD_EXER_TYP FOD_EXER_TYP,
                      FOD_OPT_TYP FOD_OPT_TYP,
                      FOD_STRK_PRC FOD_STRK_PRC,
                      FOD_ORDR_FLW FOD_ORDR_FLW,
                      FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                      NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                      FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                      NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                      NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                      FOD_ORDR_TYPE FOD_ORDR_TYPE,
                      to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                      to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                      FOD_ORDR_STTS FOD_ORDR_STTS,
                      FOD_EXEC_QTY FOD_EXEC_QTY,
                      FOD_CNCL_QTY FOD_CNCL_QTY,
                      FOD_EXPRD_QTY FOD_EXPRD_QTY,
                      NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                      NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                      FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                      NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                      FOD_SPL_FLAG FOD_SPL_FLAG,
                      NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                      NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                      NVL( FOD_BP_ID,' ') FOD_BP_ID,
                      NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,  /*** Ver 3.1 ***/
                      NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,                             /*** Ver 3.1 ***/
                      NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,                             /*** Ver 3.2 ***/
                    	NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    	NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    	NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                      FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                      FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
											NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
											NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/	
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
											FXB_RQST_TM FXB_RQST_TM     /** Added in Ver 8.8 by Vishal **/
             FROM     FOD_FO_ORDR_DTLS_HSTRY,CNT_CSE_MAST,FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/
             WHERE    FOD_XCHNG_CD   LIKE  :c_exchange_cd /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             /*** AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
						 Commented in Ver 4.0 ***/
         /***AND     FOD_PRDCT_TYP in ('F','P','O','U','I') ** Ver 4.0 Include OptionPlus orders ** Commented In Ver 4.3 ***/
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
       			 AND FOD_CSE_ID = CCM_CSE_ID
						 AND FOD_TRD_DT = to_date(:c_frm_dt,'dd-mon-yyyy') /** Added for 3.9 on 04-May-2015 **/
             AND CCM_LOGIN_NAME = :c_advisor_id
						 AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
              )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC   /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR  /** Added in Ver 8.8 by Vishal **/     
            /** ORDER BY 1,2 DESC  **/ /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
          )
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
         AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
 
          END;
          END-EXEC;
       }
			 if(DEBUG_MSG_LVL_3) /* Added debug level Ver 7.6 */
			 {
       	fn_userlog(c_ServiceName,"after query execution");
			 } 
     }
		}
    if(c_opr_typ == UNDERLYING_AND_DATE_IP)
    {
      if( DEBUG_MSG_LVL_3 )
      {
        fn_userlog(c_ServiceName,"Inside Advisor with Underlying");
      }

      if( DEBUG_MSG_LVL_3 )
      {
        fn_userlog(c_ServiceName,"li_rec_cnt_status_date [%ld]",li_rec_cnt_adv);
        fn_userlog(c_ServiceName,"c_min_ref_num [%s]",c_min_ref_num);
        fn_userlog(c_ServiceName,"c_max_ref_num [%s]",c_max_ref_num); 
      }
      if ( li_rec_cnt_adv != 1 ) 
      {

       /*** Ver 6.5 Starts ***/
       if ( c_sys_ordr_flg == 'S' )                   /*** if-else added in Ver 6.5 ***/
            {

        /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM    FOD_FO_ORDR_DTLS,ACM_ADV_CLNT_MAP
            WHERE   FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT
            AND     FOD_XCHNG_CD  LIKE  :c_exchange_cd   /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_UNDRLYNG  =    :c_underlying
            AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     FOD_CHANNEL        = 'SYS'
            AND     ACM_ACTV_FLG       = 'A'
            AND     ACM_ADVISOR_ID     = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )
                     );
                     



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31210", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31215", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

    
         EXEC SQL  EXECUTE
         BEGIN
         OPEN       :sys_cursor FOR
         SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        //FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM           /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM       /** Added in Ver 8.8 by Vishal **/
   FROM
   (
         SELECT     FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                    FOD_PIPE_ID FOD_PIPE_ID,
                    FOD_XCHNG_CD FOD_XCHNG_CD,
                    FOD_PRDCT_TYP FOD_PRDCT_TYP,
                    FOD_INDSTK FOD_INDSTK,
                    FOD_UNDRLYNG FOD_UNDRLYNG,
                    to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                    FOD_EXER_TYP FOD_EXER_TYP,
                    FOD_OPT_TYP FOD_OPT_TYP,
                    FOD_STRK_PRC FOD_STRK_PRC,
                    FOD_ORDR_FLW FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                    NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                    FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                    NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                    NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                    FOD_ORDR_TYPE FOD_ORDR_TYPE,
                    to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                    to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                    FOD_ORDR_STTS FOD_ORDR_STTS,
                    FOD_EXEC_QTY FOD_EXEC_QTY,
                    FOD_CNCL_QTY FOD_CNCL_QTY,
                    FOD_EXPRD_QTY FOD_EXPRD_QTY,
                    NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                    NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                    FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                    NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                    FOD_SPL_FLAG FOD_SPL_FLAG,
                    NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                    NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                    NVL( FOD_BP_ID,' ') FOD_BP_ID,
                    NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,
                    NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,
                    NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                                 
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                         
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                
                    FOD_FC_FLAG FOD_FC_FLAG1,                                        
                    NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                         
                    NVL(FOD_ESP_ID,'*') FOD_ESP_ID,
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/    
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,              /*** Ver 7.7 ***/                         
										FXB_RQST_TM FXB_RQST_TM                   /** Added in Ver 8.8 by Vishal **/ 
            FROM    FOD_FO_ORDR_DTLS,ACM_ADV_CLNT_MAP,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 */      
            WHERE   FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT 
            AND     FOD_XCHNG_CD  LIKE  :c_exchange_cd   /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_UNDRLYNG  =    :c_underlying
            AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     FOD_CHANNEL        = 'SYS'            
            AND     ACM_ACTV_FLG       = 'A'             
            AND     ACM_ADVISOR_ID     = :c_advisor_id  
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') ) 
                     )
					AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC  /** Added in Ver 8.8 by Vishal **/
          AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
         /* ORDER BY FOD_CLM_MTCH_ACCNT,FOD_ORDR_RFRNC DESC */ /** Commented in Ver 8.8 **/
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
					)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
					AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
        END;
        END-EXEC;
       }
       else   /*** Ver 6.5 Ends ***/
       {

         /*** Ver 8.4 Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM    FOD_FO_ORDR_DTLS,CNT_CSE_MAST
            WHERE   FOD_XCHNG_CD  LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_UNDRLYNG  =    :c_underlying
            AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     FOD_CSE_ID = CCM_CSE_ID
            AND     CCM_LOGIN_NAME = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        /** AND FOD_ORDR_VALID_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') ) ** ver 4.6 **/
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     );
                     



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31220", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}
    
      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }


   		if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31225", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


          EXEC SQL  EXECUTE
          BEGIN
            OPEN  :sys_cursor FOR
						SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        //FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM          /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM       /** Added in Ver 8.8 by Vishal **/
   FROM
   (
            SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                    FOD_PIPE_ID FOD_PIPE_ID,
                    FOD_XCHNG_CD FOD_XCHNG_CD,
                    FOD_PRDCT_TYP FOD_PRDCT_TYP,
                    FOD_INDSTK FOD_INDSTK ,
                    FOD_UNDRLYNG FOD_UNDRLYNG,
                    to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                    FOD_EXER_TYP FOD_EXER_TYP,
                    FOD_OPT_TYP FOD_OPT_TYP,
                    FOD_STRK_PRC FOD_STRK_PRC,
                    FOD_ORDR_FLW FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                    NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                    FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                    NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                    NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                    FOD_ORDR_TYPE FOD_ORDR_TYPE,
                    to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                    to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                    FOD_ORDR_STTS FOD_ORDR_STTS,
                    FOD_EXEC_QTY FOD_EXEC_QTY,
                    FOD_CNCL_QTY FOD_CNCL_QTY,
                    FOD_EXPRD_QTY FOD_EXPRD_QTY,
                    NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                    NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                    FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                    NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                    FOD_SPL_FLAG FOD_SPL_FLAG,
                    NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                    NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                    NVL( FOD_BP_ID,' ') FOD_BP_ID,
                    NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,
                    NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,
                    NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                                 /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                          /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM                 /** Added in Ver 8.8 by Vishal **/
            FROM    FOD_FO_ORDR_DTLS,CNT_CSE_MAST,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/
            WHERE   FOD_XCHNG_CD LIKE  :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_UNDRLYNG  =    :c_underlying
            AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
      			AND 		FOD_CSE_ID = CCM_CSE_ID
            AND 		CCM_LOGIN_NAME = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
           )
					AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
          AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR  /** Added in Ver 8.8 by Vishal **/        
         /* ORDER BY FOD_CLM_MTCH_ACCNT, FOD_ORDR_RFRNC DESC */ /** Commented in Ver 8.8 **/
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
 					)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
       AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
 
        END;
        END-EXEC;
       }
      
      }
       else if ( li_rec_cnt_adv == 1 ) 
       {
   
        /*** Ver 6.5 Starts ***/
        if ( c_sys_ordr_flg == 'S' )                 /** if-else added in Ver 6.5 ***/
            {
							/*** Ver 8.4 Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM     FOD_FO_ORDR_DTLS_HSTRY,ACM_ADV_CLNT_MAP
             WHERE    FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT
             AND      FOD_XCHNG_CD   LIKE :c_exchange_cd  /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_UNDRLYNG  =    :c_underlying
             AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND      ACM_ACTV_FLG       = 'A'
             AND      FOD_CHANNEL        = 'SYS'
             AND      ACM_ADVISOR_ID     = :c_advisor_id
             AND      FOD_TRD_DT        = to_date(:c_frm_dt,'dd-mon-yyyy')
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )

                      );
                     



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31230", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
        fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31235", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


       EXEC SQL  EXECUTE
              BEGIN
              OPEN  :sys_cursor FOR
              SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM           /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (
              SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                      FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                      FOD_PIPE_ID FOD_PIPE_ID,
                      FOD_XCHNG_CD FOD_XCHNG_CD,
                      FOD_PRDCT_TYP FOD_PRDCT_TYP,
                      FOD_INDSTK FOD_INDSTK,
                      FOD_UNDRLYNG FOD_UNDRLYNG,
                      to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                      FOD_EXER_TYP FOD_EXER_TYP,
                      FOD_OPT_TYP FOD_OPT_TYP,
                      FOD_STRK_PRC FOD_STRK_PRC,
                      FOD_ORDR_FLW FOD_ORDR_FLW,
                      FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                      NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                      FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                      NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                      NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                      FOD_ORDR_TYPE FOD_ORDR_TYPE,
                      to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                      to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                      FOD_ORDR_STTS FOD_ORDR_STTS,
                      FOD_EXEC_QTY FOD_EXEC_QTY,
                      FOD_CNCL_QTY FOD_CNCL_QTY,
                      FOD_EXPRD_QTY FOD_EXPRD_QTY,
                      NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                      NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                      FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                      NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                      FOD_SPL_FLAG FOD_SPL_FLAG,
                      NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                      NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                      NVL( FOD_BP_ID,' ') FOD_BP_ID,
                      NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,  
                      NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,                             
                      NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,                             
                      NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               
                      NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                             
                      NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                     
                      FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                           
                      FOD_FC_FLAG FOD_FC_FLAG1,                                  
                      NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                  
                      NVL(FOD_ESP_ID,'*') FOD_ESP_ID,
											 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/            
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /***  Ver 7.7 ***/           
										FXB_RQST_TM FXB_RQST_TM             /** Added in Ver 8.8 by Vishal **/ 
             FROM     FOD_FO_ORDR_DTLS_HSTRY,ACM_ADV_CLNT_MAP,FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/    
             WHERE    FOD_CLM_MTCH_ACCNT = ACM_MTCH_ACCNT 
             AND      FOD_XCHNG_CD  LIKE  :c_exchange_cd  /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_UNDRLYNG  =    :c_underlying
             AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND      ACM_ACTV_FLG       = 'A'                   
             AND      FOD_CHANNEL        = 'SYS'                 
             AND      ACM_ADVISOR_ID     = :c_advisor_id         
             AND      FOD_TRD_DT        = to_date(:c_frm_dt,'dd-mon-yyyy') 
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  
                        
                      )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
            /* ORDER BY 1,2 DESC */ /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
					)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
         AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 

             END;
             END-EXEC;
            } 
        else    /*** Ver 6.5 Ends ***/
            { 

       /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
      FROM     FOD_FO_ORDR_DTLS_HSTRY,CNT_CSE_MAST
             WHERE    FOD_XCHNG_CD  LIKE  :c_exchange_cd  /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_UNDRLYNG  =    :c_underlying
             AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND      FOD_CSE_ID = CCM_CSE_ID
             AND      FOD_TRD_DT = to_date(:c_frm_dt,'dd-mon-yyyy') /** Added for 3.9 on 04-May-2015 **/
             AND      CCM_LOGIN_NAME = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        /**AND FOD_ORDR_VALID_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') ) *** Ver 4.6 **/
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )
                    ); 



      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31240", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
  			fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31245", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

 
        EXEC SQL  EXECUTE
            BEGIN
              OPEN  :sys_cursor FOR
            /***  SELECT  FOD_CLM_MTCH_ACCNT,
                      FOD_ORDR_RFRNC,
                      FOD_PIPE_ID,
                      FOD_XCHNG_CD,
                      FOD_PRDCT_TYP,
                      FOD_INDSTK,
                      FOD_UNDRLYNG,
                      to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ),
                      FOD_EXER_TYP,
                      FOD_OPT_TYP,
                      FOD_STRK_PRC,
                      FOD_ORDR_FLW,
                      FOD_LMT_MRKT_SL_FLG,
                      NVL( FOD_DSCLSD_QTY, 0 ),
                      FOD_ORDR_TOT_QTY,
                      NVL( FOD_LMT_RT, 0 ),
                      NVL( FOD_STP_LSS_TGR, 0 ),
                      FOD_ORDR_TYPE,
                      to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ),
                      to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ),
                      FOD_ORDR_STTS,
                      FOD_EXEC_QTY,
                      FOD_CNCL_QTY,
                      FOD_EXPRD_QTY,
                      NVL( FOD_SPRD_ORDR_REF, ' ' ),
                      NVL( FOD_SETTLOR, ' ' ),
                      FOD_MDFCTN_CNTR,
                      NVL( FOD_ACK_NMBR, ' ' ),
                      FOD_SPL_FLAG,
                      NVL( FOD_REMARKS, ' ' ),
                      NVL( FOD_CHANNEL,'*'),
                      NVL( FOD_BP_ID,' '),
                      NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0),
                      NVL(FOD_FC_FLAG,' '),
                      NVL(FOD_SPN_FLG,'N')
              FROM    FOD_FO_ORDR_DTLS,CNT_CSE_MAST
              WHERE   FOD_XCHNG_CD      LIKE  :c_exchange_cd    
              AND     FOD_PRDCT_TYP      LIKE :c_product_typ
              AND     FOD_UNDRLYNG  =    :c_underlying
              AND     FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
              AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
              AND     FOD_ORDR_STTS      <>   'Y'
              AND     FOD_IS_FLG         LIKE :c_is_flg
        			AND 		FOD_CSE_ID = CCM_CSE_ID
              AND 		CCM_LOGIN_NAME = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_ORDR_VALID_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') )
                     )
              UNION ALL		*** Commented for history only view ***/
              SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM               /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM          /** Added in Ver 8.8 by Vishal **/
   FROM
   (
              SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
                      FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
                      FOD_PIPE_ID FOD_PIPE_ID,
                      FOD_XCHNG_CD FOD_XCHNG_CD,
                      FOD_PRDCT_TYP FOD_PRDCT_TYP,
                      FOD_INDSTK FOD_INDSTK,
                      FOD_UNDRLYNG FOD_UNDRLYNG,
                      to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT,
                      FOD_EXER_TYP FOD_EXER_TYP,
                      FOD_OPT_TYP FOD_OPT_TYP,
                      FOD_STRK_PRC FOD_STRK_PRC,
                      FOD_ORDR_FLW FOD_ORDR_FLW,
                      FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG,
                      NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
                      FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY,
                      NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
                      NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
                      FOD_ORDR_TYPE FOD_ORDR_TYPE,
                      to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT,
                      to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT,
                      FOD_ORDR_STTS FOD_ORDR_STTS,
                      FOD_EXEC_QTY FOD_EXEC_QTY,
                      FOD_CNCL_QTY FOD_CNCL_QTY,
                      FOD_EXPRD_QTY FOD_EXPRD_QTY,
                      NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
                      NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
                      FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
                      NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
                      FOD_SPL_FLAG FOD_SPL_FLAG,
                      NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
                      NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
                      NVL( FOD_BP_ID,' ') FOD_BP_ID,
                      NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,  /*** Ver 3.1 ***/
                      NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,                             /*** Ver 3.1 ***/
                      NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,                             /*** Ver 3.2 ***/
                    	NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    	NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    	NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                      FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                      FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
											NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
											NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
											 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
											FXB_RQST_TM FXB_RQST_TM                /** Added in Ver 8.8 by Vishal **/
             FROM     FOD_FO_ORDR_DTLS_HSTRY,CNT_CSE_MAST, FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/
             WHERE    FOD_XCHNG_CD  LIKE :c_exchange_cd  /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
             AND      FOD_PRDCT_TYP   LIKE :c_product_typ
             AND      FOD_UNDRLYNG  =    :c_underlying
             AND      FOD_PRDCT_TYP NOT IN ( CASE WHEN :c_product_typ = '%' THEN 'I' ELSE 'Z' END )
             AND      FOD_ORDR_STTS   LIKE :c_ordr_stts
             AND      FOD_ORDR_STTS   <> 'Y'
             AND      FOD_IS_FLG      LIKE :c_is_flg
             AND      FOD_CSE_ID = CCM_CSE_ID
						 AND      FOD_TRD_DT = to_date(:c_frm_dt,'dd-mon-yyyy') /** Added for 3.9 on 04-May-2015 **/
             AND      CCM_LOGIN_NAME = :c_advisor_id
             AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
           	)
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/         
           /* ORDER BY 1,2 DESC */ /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
					)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
         AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
 
          END;
          END-EXEC;
       }
     }
   } 

      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31250", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

   }
  /*** End for Ver 3.9 ***/
	}
	/*** Ver 2.6 ends here ***/

	else
	{
		if( DEBUG_MSG_LVL_3 ) 
		{
			fn_userlog(c_ServiceName,"--inside Single match account--");
		}

		if ( c_opr_typ == CONTRACT_IP )
		{
      if( DEBUG_MSG_LVL_3 )  /*** Ver 5.2 ***/
      {
				fn_userlog(c_ServiceName,"Order Book Inside CONTRACT_IP.");
			}

      /*** Ver 8.4 Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages 
      FROM      FOD_FO_ORDR_DTLS
          WHERE     FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
          AND       FOD_XCHNG_CD  LIKE :c_exchange_cd   /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
          AND       FOD_PRDCT_TYP      =    :c_product_typ
          AND       FOD_UNDRLYNG       =    :c_underlying
          AND       FOD_EXPRY_DT       =    to_date(:c_expiry_dt,'dd-mon-yyyy')
          AND       FOD_EXER_TYP       =    :c_exercise_type
          AND       FOD_OPT_TYP        =    :c_option_type
          AND       FOD_STRK_PRC       =    :li_strike_price
          AND       FOD_ORDR_STTS      LIKE :c_ordr_stts
          AND       FOD_ORDR_STTS      <>   'Y'
          AND       FOD_IS_FLG         LIKE :c_is_flg
          AND       NVL(FOD_ESP_ID,'*')  LIKE :c_ven_id;
      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31255", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4 Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

     if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
 				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31260", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


			/*** Ver 2.6 Starts here ***/

		  EXEC SQL	EXECUTE
				BEGIN
					OPEN	:sys_cursor	FOR
          SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM           /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
     FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  /*** Ver 3.1 ***/
     FOD_FC_FLAG,                             /*** Ver 3.1 ***/
     FOD_SPN_FLG,                             /*** Ver 3.2 ***/
     FOD_TRD_VAL,                               /*** Ver 4.1 ***/
     FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
     FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
     FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
     FOD_ESP_ID,                                 /*** Ver 6.4 ***/
     FOD_1CLICK_FLG,             /*** ver 6.9 **/
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM           /** Added in Ver 8.8 by Vishal **/
   FROM
   (
					SELECT  	FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP, 
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP ,
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC, 
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS, 
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY,
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF, 
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                            /*** Ver 7.7 ***/
                    FXB_RQST_TM FXB_RQST_TM     /** Added in Ver 8.8 by Vishal **/
					FROM			FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/
					WHERE			FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
          AND       FOD_XCHNG_CD   LIKE :c_exchange_cd   /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
					AND				FOD_PRDCT_TYP      =		:c_product_typ
					AND				FOD_UNDRLYNG       =		:c_underlying
					AND				FOD_EXPRY_DT       =		to_date(:c_expiry_dt,'dd-mon-yyyy')
					AND				FOD_EXER_TYP       =		:c_exercise_type
					AND				FOD_OPT_TYP        =		:c_option_type
					AND				FOD_STRK_PRC       =		:li_strike_price
					AND				FOD_ORDR_STTS			 LIKE :c_ordr_stts
					AND				FOD_ORDR_STTS			 <>		'Y'										
					AND				FOD_IS_FLG				 LIKE :c_is_flg     
					AND       NVL(FOD_ESP_ID,'*')	 LIKE :c_ven_id     /*** Ver 6.4 ***/
					AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
          AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
					/** ORDER BY 1,2 DESC **/ /** Commented in Ver 8.8 **/
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/ 
        )
				),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
        AND REC_INDEX >=:l_start_rec_no
	  AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
	
      END;
			END-EXEC;
			/*** Ver 2.6 Ends here ***/
		}
		else if ( c_opr_typ == CONTRACT_AND_DATE_IP )
		{
		  if( DEBUG_MSG_LVL_3 )  /*** Ver 5.2 ***/
      {	
      	fn_userlog(c_ServiceName,"Order Book Inside CONTRACT_AND_DATE_IP");
      }

			if ( c_date_flag == 'N' )
			{
				fn_userlog( c_ServiceName,"From/To Dates are not Found in the Buffer" );
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
				tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}

			/*** Ver 2.6 starts here ***/
      if ( DEBUG_MSG_LVL_3)
      {
		 	 fn_userlog(c_ServiceName,"Data Fetch Counter Is :%ld:",li_rec_cnt_status_date);
			}
    
			if ( li_rec_cnt_status_date != 1 )			/***	Added In Ver 4.3	***/
			{

        /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
           FROM  FOD_FO_ORDR_DTLS
            WHERE FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
            AND    FOD_XCHNG_CD   LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
            AND   FOD_PRDCT_TYP      =    :c_product_typ
            AND   FOD_UNDRLYNG       =    :c_underlying
            AND   FOD_EXPRY_DT       =    to_date( :c_expiry_dt,'dd-mon-yyyy')
            AND   FOD_EXER_TYP       =    :c_exercise_type
            AND   FOD_OPT_TYP        =    :c_option_type
            AND   FOD_STRK_PRC       =    :li_strike_price
            AND   FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND   FOD_ORDR_STTS      <>   'Y'
            AND   FOD_IS_FLG         LIKE :c_is_flg
            AND   NVL(FOD_ESP_ID,'*')  LIKE :c_ven_id
            AND   FOD_TRD_DT between :c_frm_dt and :c_to_dt;

      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31265", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }


   		if(l_page_no < 1)
    	{
				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31270", FMLMSG , c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM
            (
						SELECT  FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC,
                    FOD_PIPE_ID,
                    FOD_XCHNG_CD,
                    FOD_PRDCT_TYP,
                    FOD_INDSTK,
                    FOD_UNDRLYNG,
                    FOD_EXPRY_DT,
                    FOD_EXER_TYP,
                    FOD_OPT_TYP,
                    FOD_STRK_PRC,
                    FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG,
                    FOD_DSCLSD_QTY, 
                    FOD_ORDR_TOT_QTY,
                    FOD_LMT_RT, 
                    FOD_STP_LSS_TGR,
                    FOD_ORDR_TYPE,
                     FOD_ORDR_VALID_DT,
                     FOD_TRD_DT,
                    FOD_ORDR_STTS,
                    FOD_EXEC_QTY,
                    FOD_CNCL_QTY,
                    FOD_EXPRD_QTY,
                     FOD_SPRD_ORDR_REF,
                     FOD_SETTLOR,
                    FOD_MDFCTN_CNTR,
                     FOD_ACK_NMBR,
                    FOD_SPL_FLAG,
                     FOD_REMARKS,
                     FOD_CHANNEL,
                     FOD_BP_ID,
                    FOD_AMT_BLCKD,  
                    FOD_FC_FLAG,                             
                    FOD_SPN_FLG,                             
                    FOD_TRD_VAL,                               
                    FOD_TRD_BRKG,                              
                    FOD_CNTRCTNT_NMBR,                        
                    FOD_SLTP_ORDR_RFRNC,                                
                    FOD_FC_FLAG1,                                         
                    FOD_PRCIMPV_FLG,                         
                    FOD_ESP_ID,                                  
                    FOD_1CLICK_FLG,             
                    FOD_SOURCE_FLG,
                    ROWNUM REC_INDEX,
										FXB_RQST_TM    /** Added in Ver 8.8 by Vishal **/
                    FROM
          (
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF, 
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N')FOD_1CLICK_FLG,             /*** ver 6.9 ***/	
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                            /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
						FROM  FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/		
						WHERE	FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
            AND    FOD_XCHNG_CD    LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
						AND		FOD_PRDCT_TYP			 =		:c_product_typ
						AND		FOD_UNDRLYNG			 =		:c_underlying
						AND		FOD_EXPRY_DT			 =		to_date( :c_expiry_dt,'dd-mon-yyyy')
						AND		FOD_EXER_TYP			 =		:c_exercise_type
						AND		FOD_OPT_TYP				 =		:c_option_type
						AND		FOD_STRK_PRC			 =		:li_strike_price
						AND		FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND		FOD_ORDR_STTS			 <>		'Y'											
						AND   FOD_IS_FLG         LIKE :c_is_flg      
						AND   NVL(FOD_ESP_ID,'*')	 LIKE :c_ven_id    
            AND   FOD_TRD_DT between :c_frm_dt and :c_to_dt
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
        /**  ORDER BY 1,2 DESC **/ /** Commented in Ver 8.8 **/
					 ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
          )
						),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
        AND REC_INDEX >=:l_start_rec_no
		  AND    REC_INDEX <=:l_end_rec_no
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
	
        END;
				END-EXEC;
			}
			/*** else if ( li_rec_cnt_contract_date == 1 )	Commented In Ver 4.3	***/
			else if ( li_rec_cnt_status_date == 1 )			/***	Added In Ver 4.3	***/
			{

       /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
            FROM
     (
          SELECT FOD_ORDR_RFRNC
          FROM  FOD_FO_ORDR_DTLS
            WHERE FOD_CLM_MTCH_ACCNT  =     :c_mtch_accnt_no
            AND  FOD_XCHNG_CD   LIKE :c_exchange_cd  /*** Ver 2.8 ***/    /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
            AND FOD_PRDCT_TYP         =     :c_product_typ
            AND FOD_UNDRLYNG          =     :c_underlying
            AND FOD_EXPRY_DT          =     to_date( :c_expiry_dt,'dd-mon-yyyy')
            AND FOD_EXER_TYP          =     :c_exercise_type
            AND FOD_OPT_TYP           =     :c_option_type
            AND FOD_STRK_PRC          =     :li_strike_price
            AND FOD_ORDR_STTS         LIKE  :c_ordr_stts
            AND   FOD_ORDR_STTS       <>    'Y'
            AND  FOD_IS_FLG           LIKE  :c_is_flg
            AND NVL(FOD_ESP_ID,'*')   LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
            UNION ALL
      select FOD_ORDR_RFRNC
      FROM  FOD_FO_ORDR_DTLS_HSTRY
            WHERE FOD_CLM_MTCH_ACCNT = :c_mtch_accnt_no
            AND FOD_XCHNG_CD  LIKE :c_exchange_cd   /** Ver 2.8 ***//*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
            AND FOD_PRDCT_TYP      = :c_product_typ
            AND FOD_UNDRLYNG       = :c_underlying
            AND FOD_EXPRY_DT       = to_date( :c_expiry_dt,'dd-mon-yyyy')
            AND FOD_EXER_TYP       = :c_exercise_type
            AND FOD_OPT_TYP        = :c_option_type
            AND FOD_STRK_PRC       = :li_strike_price
            AND FOD_ORDR_STTS   LIKE :c_ordr_stts
            AND   FOD_ORDR_STTS   <> 'Y'
            AND  FOD_IS_FLG      LIKE :c_is_flg
            AND NVL(FOD_ESP_ID,'*')  LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
          );

      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31275", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31280", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
									 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /***  Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
						FROM  FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/		
						WHERE	FOD_CLM_MTCH_ACCNT	=			:c_mtch_accnt_no
            AND  FOD_XCHNG_CD   LIKE :c_exchange_cd  /*** Ver 2.8 ***/    /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
						AND	FOD_PRDCT_TYP					=			:c_product_typ
						AND	FOD_UNDRLYNG					=			:c_underlying
						AND	FOD_EXPRY_DT					=			to_date( :c_expiry_dt,'dd-mon-yyyy')
						AND	FOD_EXER_TYP					=			:c_exercise_type
						AND	FOD_OPT_TYP						=			:c_option_type
						AND	FOD_STRK_PRC					=			:li_strike_price
						AND	FOD_ORDR_STTS					LIKE	:c_ordr_stts 
						AND 	FOD_ORDR_STTS				<>		'Y'										
						AND  FOD_IS_FLG						LIKE	:c_is_flg   
						AND NVL(FOD_ESP_ID,'*') 	LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
					  UNION ALL  		
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE  FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL, 											
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,   	                          /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                         /*** Ver 5.5 ***/	
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /***  Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
						FROM  FOD_FO_ORDR_DTLS_HSTRY,FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/		
						WHERE	FOD_CLM_MTCH_ACCNT = :c_mtch_accnt_no
            AND FOD_XCHNG_CD  LIKE :c_exchange_cd   /**8 Ver 2.8 ***//*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
						AND	FOD_PRDCT_TYP      = :c_product_typ
						AND	FOD_UNDRLYNG       = :c_underlying
						AND	FOD_EXPRY_DT       = to_date( :c_expiry_dt,'dd-mon-yyyy')
						AND	FOD_EXER_TYP       = :c_exercise_type
						AND	FOD_OPT_TYP        = :c_option_type
						AND	FOD_STRK_PRC       = :li_strike_price
						AND	FOD_ORDR_STTS   LIKE :c_ordr_stts 
						AND 	FOD_ORDR_STTS		<> 'Y'											
						AND  FOD_IS_FLG      LIKE :c_is_flg   
						AND NVL(FOD_ESP_ID,'*')	 LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
						AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
         /** ORDER BY 1,2 DESC **/  /**Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
					)
          ),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
				  AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
	
        END;
				END-EXEC;
			}
			/*** Ver 2.6 Ends here ***/
		}
		
		else if ( c_opr_typ == UNDERLYING_IP )
		{
     
     if( DEBUG_MSG_LVL_3 )  /*** Ver 5.2 ***/
     {
     	 fn_userlog(c_ServiceName,"Order Book Inside UNDERLYING_IP.");
     }


     /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
           FROM      FOD_FO_ORDR_DTLS
          WHERE     FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
          AND       FOD_XCHNG_CD       LIKE : c_exchange_cd     /**LIKE added in Ver 8.8**/   
          AND       FOD_UNDRLYNG       =    :c_underlying
          AND       FOD_PRDCT_TYP      LIKE :c_product_typ
          AND       FOD_ORDR_STTS      LIKE :c_ordr_stts
          AND       FOD_ORDR_STTS      <>   'Y'
          AND       FOD_IS_FLG         LIKE :c_is_flg
          AND       NVL(FOD_ESP_ID,'*')  LIKE :c_ven_id;    
          
			if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31285", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

     if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31290", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/


			/*** Ver 2.6 starts here ***/

			EXEC SQL	EXECUTE
				BEGIN
					OPEN	:sys_cursor	FOR
		   SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM
            (
						SELECT    FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC,
                    FOD_PIPE_ID,
                    FOD_XCHNG_CD,
                    FOD_PRDCT_TYP,
                    FOD_INDSTK,
                    FOD_UNDRLYNG,
                    FOD_EXPRY_DT, 
                    FOD_EXER_TYP,
                    FOD_OPT_TYP,
                    FOD_STRK_PRC,
                    FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG,
                    FOD_DSCLSD_QTY,
                    FOD_ORDR_TOT_QTY,
                    FOD_LMT_RT,
                    FOD_STP_LSS_TGR,
                    FOD_ORDR_TYPE,
                    FOD_ORDR_VALID_DT, 
                    FOD_TRD_DT, 
                    FOD_ORDR_STTS,
                    FOD_EXEC_QTY,
                    FOD_CNCL_QTY,
                    FOD_EXPRD_QTY,
                    FOD_SPRD_ORDR_REF,
                    FOD_SETTLOR,
                    FOD_MDFCTN_CNTR,
                    FOD_ACK_NMBR,
                    FOD_SPL_FLAG,
                    FOD_REMARKS,
                    FOD_CHANNEL,
                    FOD_BP_ID,
                    FOD_AMT_BLCKD, 
                    FOD_FC_FLAG,                             
                    FOD_SPN_FLG,                            
                    FOD_TRD_VAL,                               
                    FOD_TRD_BRKG,                              
                    FOD_CNTRCTNT_NMBR,                        
                    FOD_SLTP_ORDR_RFRNC,                               
                    FOD_FC_FLAG1,                                         
                    FOD_PRCIMPV_FLG,                          
                    FOD_ESP_ID,                                  
                    FOD_1CLICK_FLG,            
                    FOD_SOURCE_FLG, 
		    						ROWNUM REC_INDEX,
										FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (			
					SELECT    FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,   
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP, 
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP,
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC, 
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS, 
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY,
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                     
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
					FROM			FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/
					WHERE			FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
          AND       FOD_XCHNG_CD       LIKE :c_exchange_cd  /*** Ver 2.8 ***//*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8**/
					AND				FOD_UNDRLYNG       =		:c_underlying
					AND				FOD_PRDCT_TYP			 LIKE :c_product_typ
					AND				FOD_ORDR_STTS			 LIKE :c_ordr_stts 
					AND				FOD_ORDR_STTS			 <>		'Y'											
					AND				FOD_IS_FLG				 LIKE :c_is_flg   
					AND       NVL(FOD_ESP_ID,'*')	 LIKE :c_ven_id     /*** Ver 6.4 ***/
				  AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
					AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
					/** ORDER BY 1,2 DESC **/ /** Commented in Ver 8.8 **/
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
					 )
						),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
        AND REC_INDEX >=:l_start_rec_no
			  AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
	
      END;
			END-EXEC;

			/*** Ver 2.6 Ends here ***/
		}

		else if ( c_opr_typ == UNDERLYING_AND_DATE_IP )
		{
      if( DEBUG_MSG_LVL_3 )  /*** Ver 5.2 ***/
      { 
      	fn_userlog(c_ServiceName,"Order Book Inside UNDERLYING_AND_DATE_IP.");
		  }
    
    	if ( c_date_flag == 'N' )
			{
				fn_userlog( c_ServiceName,"From/To Dates are not Found in the Buffer" );
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
				tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}

			/*** Ver 2.6 starts here ***/

      if ( DEBUG_MSG_LVL_3)
      {
       fn_userlog(c_ServiceName,"li_rec_cnt_status_date :%ld:",li_rec_cnt_status_date);
      }


			/*** if ( li_rec_cnt_undrlng_date != 1 ) Commented In Ver 4.3	***/
			if ( li_rec_cnt_status_date != 1 )			/***	Added In Ver 4.3	***/
			{

        /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
           FROM    FOD_FO_ORDR_DTLS
            WHERE   FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
            AND      FOD_XCHNG_CD      LIKE :c_exchange_cd    /**LIKE added in Ver 8.8*/
            AND     FOD_UNDRLYNG       =    :c_underlying
            AND     FOD_PRDCT_TYP      LIKE decode(:c_product_typ,'X','%',:c_product_typ)
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND    DECODE(:c_product_typ,'X',FOD_SOURCE_FLG,NVL(FOD_ESP_ID,'*')) like DECODE(:c_product_typ,'X','F',:c_ven_id)
            AND     FOD_TRD_DT between :c_frm_dt and :c_to_dt ;

      if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31295", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

 		  if(l_page_no < 1)
    	{
				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31300", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
					SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM
            (
						SELECT  FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC,
                    FOD_PIPE_ID,
                    FOD_XCHNG_CD,
                    FOD_PRDCT_TYP,
                    FOD_INDSTK,
                    FOD_UNDRLYNG,
                    FOD_EXPRY_DT, 
                    FOD_EXER_TYP,
                    FOD_OPT_TYP,
                    FOD_STRK_PRC,
                    FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG,
                     FOD_DSCLSD_QTY, 
                    FOD_ORDR_TOT_QTY,
                     FOD_LMT_RT, 
                     FOD_STP_LSS_TGR, 
                    FOD_ORDR_TYPE,
                    FOD_ORDR_VALID_DT, 
                    FOD_TRD_DT, 
                    FOD_ORDR_STTS,
                    FOD_EXEC_QTY,
                    FOD_CNCL_QTY,
                    FOD_EXPRD_QTY,
                     FOD_SPRD_ORDR_REF, 
                     FOD_SETTLOR, 
                    FOD_MDFCTN_CNTR,
                     FOD_ACK_NMBR, 
		    FOD_SPL_FLAG,
                     FOD_REMARKS, 
                     FOD_CHANNEL,
                     FOD_BP_ID,
                    FOD_AMT_BLCKD,
                    FOD_FC_FLAG,                               
                    FOD_SPN_FLG,                               
                    FOD_TRD_VAL,                                 
                    FOD_TRD_BRKG,                                
                    FOD_CNTRCTNT_NMBR,                          
                    FOD_SLTP_ORDR_RFRNC,                                
                    FOD_FC_FLAG1,                                
                     FOD_PRCIMPV_FLG,                           
                    FOD_ESP_ID,                                
                     FOD_1CLICK_FLG,             
                    FOD_SOURCE_FLG,
		    ROWNUM REC_INDEX,
				FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT,  
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,  
										FOD_PIPE_ID FOD_PIPE_ID,     
										FOD_XCHNG_CD FOD_XCHNG_CD,    
										FOD_PRDCT_TYP FOD_PRDCT_TYP,   
										FOD_INDSTK FOD_INDSTK,      
										FOD_UNDRLYNG FOD_UNDRLYNG,    
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                     
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,		/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,																/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															  /*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                                 /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                                /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                          /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
						FROM		FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/		
						WHERE		FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
            AND      FOD_XCHNG_CD      LIKE  :c_exchange_cd   /*** Ver 2.8 ***//*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
						AND			FOD_UNDRLYNG       =		:c_underlying
						AND     FOD_PRDCT_TYP      LIKE decode(:c_product_typ,'X','%',:c_product_typ) /* Ver 7.4 */
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND 		FOD_ORDR_STTS			 <>		'Y'											
						AND			FOD_IS_FLG				 LIKE :c_is_flg              
						AND    DECODE(:c_product_typ,'X',FOD_SOURCE_FLG,NVL(FOD_ESP_ID,'*')) like DECODE(:c_product_typ,'X','F',:c_ven_id) /* ver 7.4 */
            AND     FOD_TRD_DT between :c_frm_dt and :c_to_dt
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/     
         /** ORDER BY FOD_CLM_MTCH_ACCNT, FOD_ORDR_RFRNC DESC **/ /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
 					)
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
        AND REC_INDEX >=:l_start_rec_no
			    AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
	
        END;
				END-EXEC;
			}
			/**else if ( li_rec_cnt_undrlng_date == 1 )	Commented In Ver 4.3	***/
			else if ( li_rec_cnt_status_date == 1 )			/*** Added In Ver 4.3 ***/
			{
 
       /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
            FROM      
	   (
          SELECT FOD_ORDR_RFRNC
          FROM    FOD_FO_ORDR_DTLS
            WHERE   FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
            AND     FOD_XCHNG_CD       LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /***LIKE added in Ver 8.8*/
            AND     FOD_UNDRLYNG       =    :c_underlying
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     NVL(FOD_ESP_ID,'*') LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
            UNION ALL
	    select FOD_ORDR_RFRNC
	    FROM    FOD_FO_ORDR_DTLS_HSTRY
            WHERE   FOD_CLM_MTCH_ACCNT = :c_mtch_accnt_no
            /*** AND      FOD_XCHNG_CD       = :c_exchange_cd *** Ver 2.8 ***/
            AND      FOD_XCHNG_CD  LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
            AND     FOD_UNDRLYNG       = :c_underlying
            AND     FOD_PRDCT_TYP   LIKE :c_product_typ
            AND     FOD_ORDR_STTS   LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS   <> 'Y'
            AND     FOD_IS_FLG      LIKE :c_is_flg
            AND     NVL(FOD_ESP_ID,'*')  LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
          ); 
          
		  if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31305", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/
      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31310", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/
 

				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
						SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  
     FOD_FC_FLAG,                             
     FOD_SPN_FLG,                             
     FOD_TRD_VAL,                               
     FOD_TRD_BRKG,                              
     FOD_CNTRCTNT_NMBR,                        
     FOD_SLTP_ORDR_RFRNC,                               
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          
     FOD_ESP_ID,                                 
     FOD_1CLICK_FLG,             
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP  FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                      
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/		
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID, 																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 **/  
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /***  Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
						FROM		FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/		
						WHERE		FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
            AND     FOD_XCHNG_CD       LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
						AND			FOD_UNDRLYNG       =		:c_underlying
						AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND 		FOD_ORDR_STTS			 <>		'Y'											
						AND			FOD_IS_FLG				 LIKE :c_is_flg  
						AND     NVL(FOD_ESP_ID,'*') LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
        		AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
						UNION ALL

						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                     
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
						FROM		FOD_FO_ORDR_DTLS_HSTRY,FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/		
						WHERE		FOD_CLM_MTCH_ACCNT = :c_mtch_accnt_no
						/*** AND			FOD_XCHNG_CD       = :c_exchange_cd *** Ver 2.8 ***/
            AND      FOD_XCHNG_CD   LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /**LIKE added in Ver 8.8*/
						AND			FOD_UNDRLYNG       = :c_underlying
						AND			FOD_PRDCT_TYP   LIKE :c_product_typ
						AND			FOD_ORDR_STTS   LIKE :c_ordr_stts 
						AND			FOD_ORDR_STTS		<> 'Y'											
						AND			FOD_IS_FLG      LIKE :c_is_flg   
						AND     NVL(FOD_ESP_ID,'*')	 LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >= to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
				    AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
          /** ORDER BY 1,2 DESC **/ /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
         )
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
				  AND    REC_INDEX <=:l_end_rec_no 
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/	
        END;
				END-EXEC;
			}
			/*** Ver 2.6 ends here ***/
		}

		else if ( c_opr_typ == STATUS_PRODUCT_IP )
		{
     /*** Ver 8.4 nikhil Starts here ***/
      EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
            FROM      FOD_FO_ORDR_DTLS
          WHERE     FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
          AND       FOD_XCHNG_CD       LIKE :c_exchange_cd    /*LIKE added in Ver 8.8*/ 
          AND       FOD_PRDCT_TYP      LIKE :c_product_typ
          AND       FOD_ORDR_STTS      LIKE :c_ordr_stts
          AND       FOD_ORDR_STTS      <>   'Y'
          AND       FOD_IS_FLG         LIKE :c_is_flg
          AND       NVL(FOD_ESP_ID,'*')  LIKE :c_ven_id;  
          
			if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
      {
        fn_errlog( c_ServiceName, "S31315", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      /*** ver 8.4  nikhil Ends here ***/

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31320", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

			/*** Ver 2.6 starts here ***/

			EXEC SQL	EXECUTE
				BEGIN
					OPEN	:sys_cursor	FOR
         SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_FC_FLAG1,
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM
            (
				SELECT  FOD_CLM_MTCH_ACCNT,
                    FOD_ORDR_RFRNC,
                    FOD_PIPE_ID,
                    FOD_XCHNG_CD,
                    FOD_PRDCT_TYP,
                    FOD_INDSTK,
                    FOD_UNDRLYNG,
                    FOD_EXPRY_DT, 
                    FOD_EXER_TYP,
                    FOD_OPT_TYP,
                    FOD_STRK_PRC,
                    FOD_ORDR_FLW,
                    FOD_LMT_MRKT_SL_FLG,
                     FOD_DSCLSD_QTY, 
                    FOD_ORDR_TOT_QTY,
                     FOD_LMT_RT, 
                     FOD_STP_LSS_TGR, 
                    FOD_ORDR_TYPE,
                    FOD_ORDR_VALID_DT, 
                    FOD_TRD_DT, 
                    FOD_ORDR_STTS,
                    FOD_EXEC_QTY,
                    FOD_CNCL_QTY,
                    FOD_EXPRD_QTY,
                     FOD_SPRD_ORDR_REF, 
                     FOD_SETTLOR, 
                    FOD_MDFCTN_CNTR,
                     FOD_ACK_NMBR, 
		   							 FOD_SPL_FLAG,
                     FOD_REMARKS, 
                     FOD_CHANNEL,
                     FOD_BP_ID,
                    FOD_AMT_BLCKD,
                    FOD_FC_FLAG,                               
                    FOD_SPN_FLG,                               
                    FOD_TRD_VAL,                                 
                    FOD_TRD_BRKG,                                
                    FOD_CNTRCTNT_NMBR,                          
                    FOD_SLTP_ORDR_RFRNC,                                
                    FOD_FC_FLAG1,                                
                    FOD_PRCIMPV_FLG,                           
                    FOD_ESP_ID,                                
                    FOD_1CLICK_FLG,             
                    FOD_SOURCE_FLG,
		    						ROWNUM REC_INDEX,
										FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (
					SELECT    FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP, 
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP,
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC, 
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY,
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT,
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR,
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS, 
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY,
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                      
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                    FOD_FC_FLAG FOD_FC_FLAG1,                                         /*** Ver 4.7 ***/
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                           /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
					FROM			FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/
					WHERE			FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
          AND       FOD_XCHNG_CD       LIKE :c_exchange_cd  /** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8*/
					AND				FOD_PRDCT_TYP			 LIKE :c_product_typ
					AND				FOD_ORDR_STTS			 LIKE :c_ordr_stts 
					AND 			FOD_ORDR_STTS			 <>		'Y'											
					AND				FOD_IS_FLG				 LIKE :c_is_flg 
					AND       NVL(FOD_ESP_ID,'*')	 LIKE :c_ven_id     /*** Ver 6.4 ***/
					AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
				  AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
					/** ORDER BY 1,2 DESC **/ /** Commented in Ver 8.8 **/
					ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
           )
					),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
        AND REC_INDEX >=:l_start_rec_no
			  AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/	
      END;
			END-EXEC;
			/*** Ver 2.6 ends here ***/
		}
		
		else if ( c_opr_typ == STATUS_PRODUCT_AND_DATE_IP )
		{
			
      if( DEBUG_MSG_LVL_3 )  /*** Ver 5.2 ***/  /*** ver 5.3, debug level changed from 1 to 3 ***/
      {
      	fn_userlog(c_ServiceName,"Order Book STATUS_PRODUCT_AND_DATE_IP.");
      	fn_userlog(c_ServiceName,"Order Book c_min_ref_num Is :%s:.",c_min_ref_num);
				fn_userlog(c_ServiceName,"Order Book c_max_ref_num Is :%s:.",c_max_ref_num); 
      }

			if ( c_date_flag == 'N' )
			{
				fn_userlog( c_ServiceName,"From/To Dates are not Found in the Buffer" );
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
				tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}

      if ( DEBUG_MSG_LVL_3)
      { 
	  		fn_userlog(c_ServiceName,"Order Book li_rec_cnt_status_date Is :%ld:",li_rec_cnt_status_date);
      }

			/*** Ver 2.6 starts here ***/

			if ( li_rec_cnt_status_date != 1 )
			{

       /*** Ver 8.4 Starts Here ***/
       EXEC SQL
          SELECT CEIL(count(1)/ :l_page_rec_cnt)
            INTO   :l_tot_pages
            FROM    FOD_FO_ORDR_DTLS
            WHERE   FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
            AND      FOD_XCHNG_CD      LIKE :c_exchange_cd  /*LIKE added in Ver 8.8*/
            AND     FOD_PRDCT_TYP      LIKE :c_product_typ
            AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
            AND     FOD_ORDR_STTS      <>   'Y'
            AND     FOD_IS_FLG         LIKE :c_is_flg
            AND     NVL(FOD_ESP_ID,'*')    LIKE :c_ven_id 
            AND     FOD_TRD_DT between :c_frm_dt and :c_to_dt;   
       if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
       {
        fn_errlog( c_ServiceName, "S31325", SQLMSG, c_errmsg  );
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
       }  

      /**** ver 8.9 start nikhil ****/

  		if(DEBUG_MSG_LVL_3)
  		{
    		fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  		}

      if(l_tot_pages == 0) {
        l_tot_pages = 1;
      }

   		if(l_page_no < 1)
    	{
				fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      	fn_errlog( c_ServiceName, "S31330", FMLMSG, c_errmsg  );
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  		}

  /**** ver 8.9 end nikhil ****/

       /*** ver 8.4  Ends Here ***/
				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
                        FOD_EXPRY_DT,
                        FOD_EXER_TYP,
                        FOD_OPT_TYP,
                        FOD_STRK_PRC,
                        FOD_ORDR_FLW,
                        FOD_LMT_MRKT_SL_FLG,
                        FOD_DSCLSD_QTY,
                        FOD_ORDR_TOT_QTY,
                        FOD_LMT_RT,
                        FOD_STP_LSS_TGR,
                        FOD_ORDR_TYPE,
                        FOD_ORDR_VALID_DT,
                        FOD_TRD_DT,
                        FOD_ORDR_STTS,
                        FOD_EXEC_QTY,
                        FOD_CNCL_QTY,
                        FOD_EXPRD_QTY,
                        FOD_SPRD_ORDR_REF,
                        FOD_SETTLOR,
                        FOD_MDFCTN_CNTR,
                        FOD_ACK_NMBR,
                        FOD_SPL_FLAG,
												FOD_REMARKS,
                        FOD_CHANNEL,
                        FOD_BP_ID,
                        FOD_AMT_BLCKD,
                        FOD_FC_FLAG,
                        FOD_SPN_FLG,
                        FOD_TRD_VAL,
                        FOD_TRD_BRKG,
                        FOD_CNTRCTNT_NMBR,
                        FOD_SLTP_ORDR_RFRNC,
                        FOD_SOURCE_FLG1, 
                        FOD_PRCIMPV_FLG,
                        FOD_ESP_ID,
												FOD_1CLICK_FLG,
                        FOD_SOURCE_FLG,
												NVL(FTQ_LST_TRD_PRC,0),
                        NVL(FTQ_TRAIL_FLG,'N'),
												FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
            FROM 
            (
              SELECT 		FOD_CLM_MTCH_ACCNT,
		 										FOD_ORDR_RFRNC,
											  FOD_PIPE_ID,
		 										FOD_XCHNG_CD,
		 										FOD_PRDCT_TYP,
		 										FOD_INDSTK,
												FOD_UNDRLYNG,
		 FOD_EXPRY_DT,
		 FOD_EXER_TYP,
		 FOD_OPT_TYP,
		 FOD_STRK_PRC,
		 FOD_ORDR_FLW,
		 FOD_LMT_MRKT_SL_FLG,
		 FOD_DSCLSD_QTY,
		 FOD_ORDR_TOT_QTY,
		 FOD_LMT_RT,
		 FOD_STP_LSS_TGR,
		 FOD_ORDR_TYPE,
		 FOD_ORDR_VALID_DT,
		 FOD_TRD_DT,
		 FOD_ORDR_STTS,
		 FOD_EXEC_QTY,
		 FOD_CNCL_QTY,
		 FOD_EXPRD_QTY,
		 FOD_SPRD_ORDR_REF,
		 FOD_SETTLOR,
		 FOD_MDFCTN_CNTR,
		 FOD_ACK_NMBR,
		 FOD_SPL_FLAG,
		 FOD_REMARKS,
		 FOD_CHANNEL,
		 FOD_BP_ID,
		 FOD_AMT_BLCKD,  /*** Ver 3.1 ***/
		 FOD_FC_FLAG,                             /*** Ver 3.1 ***/
		 FOD_SPN_FLG,                             /*** Ver 3.2 ***/
		 FOD_TRD_VAL,                               /*** Ver 4.1 ***/
		 FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
		 FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
		 FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
		 FOD_SOURCE_FLG1,
		 FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
		 FOD_ESP_ID,                                 /*** Ver 6.4 ***/
		 FOD_1CLICK_FLG,             /*** ver 6.9 **/
		 FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
     FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/ 
   FROM
   (            
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                      
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
										DECODE(FOD_SOURCE_FLG,'F',DECODE(FOD_PRDCT_TYP,'O',' ',FOD_FC_FLAG),FOD_FC_FLAG) FOD_SOURCE_FLG1,
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,																	/*** Ver 6.4 ***/
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             /*** ver 6.9 **/ 
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,                            /*** Ver 7.7 ***/
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/
						FROM		FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK Added in Ver 8.8 **/		
						WHERE		FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
            AND      FOD_XCHNG_CD      LIKE :c_exchange_cd   /* LIKE added in Ver 8.8 */ 
						AND     FOD_PRDCT_TYP      LIKE :c_product_typ 
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND			FOD_ORDR_STTS			 <>		'Y'							
						AND			FOD_IS_FLG				 LIKE :c_is_flg 
						AND     NVL(FOD_ESP_ID,'*')		 LIKE :c_ven_id  
            AND     FOD_TRD_DT between :c_frm_dt and :c_to_dt
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC     /** Added in Ver 8.8 by Vishal **/
            AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR    /** Added in Ver 8.8 by Vishal **/ 
            /** ORDER BY FOD_CLM_MTCH_ACCNT,FOD_ORDR_RFRNC DESC   Commented in Ver 8.8 **/ 
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
         )
						),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
        		AND REC_INDEX >=:l_start_rec_no
				  	AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/
        END;
				END-EXEC;
			}
			
			else if ( li_rec_cnt_status_date == 1 ) 
			{
         /****** Ver 8.4 Starts Here ****/
        EXEC SQL
            SELECT CEIL(count(1)/ :l_page_rec_cnt)
              INTO :l_tot_pages 
					    FROM
					    (
					    SELECT FOD_ORDR_RFRNC
					    FROM    FOD_FO_ORDR_DTLS
					    WHERE   FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
					    AND     FOD_XCHNG_CD       LIKE :c_exchange_cd   /*LIKE added in Ver 8.8**/
					    AND     FOD_PRDCT_TYP      LIKE :c_product_typ
					    AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
					    AND     FOD_ORDR_STTS      <>   'Y'
					    AND     FOD_IS_FLG         LIKE :c_is_flg
					    AND     NVL(FOD_ESP_ID,'*')    LIKE :c_ven_id  
					    AND
						     (
						      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
							AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
						      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
							AND FOD_TRD_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') ) 
						     )
					    UNION ALL
					    SELECT  FOD_ORDR_RFRNC
					    FROM    FOD_FO_ORDR_DTLS_HSTRY
					    WHERE   FOD_CLM_MTCH_ACCNT =    :c_mtch_accnt_no
					    AND      FOD_XCHNG_CD      LIKE :c_exchange_cd     /*LIKE added in Ver 8.8 **/
					    AND     FOD_PRDCT_TYP      LIKE :c_product_typ
					    AND     FOD_ORDR_STTS      LIKE :c_ordr_stts
					    AND     FOD_ORDR_STTS      <>   'Y'
					    AND     FOD_IS_FLG         LIKE :c_is_flg
					    AND     NVL(FOD_ESP_ID,'*')  LIKE :c_ven_id   
					    AND
						     (
						      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
							AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
						      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
							AND FOD_TRD_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') )
						     )
					  );
            if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
            {
  			      fn_errlog( c_ServiceName, "S31335", SQLMSG, c_errmsg  );
      			  Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      			  tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      			}
    
       /**** ver 8.9 start nikhil ****/

  			if(DEBUG_MSG_LVL_3)
  			{
    			fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_no,l_tot_pages);
  			}

        if(l_tot_pages == 0) {
        	 l_tot_pages = 1;
      	}

   			if(l_page_no < 1)
    		{
					fn_userlog(c_ServiceName,"Invalid Pages number count is :%ld: Total pages:%ld:",l_page_no,l_tot_pages);
      		fn_errlog( c_ServiceName, "S31340", FMLMSG, c_errmsg  );
      		Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      		Fchg32(ptr_fml_ibuf,FFO_REC_NO,0,(char *)&l_tot_pages,0);
      		tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  			}

  /**** ver 8.9 end nikhil ****/


				EXEC SQL	EXECUTE
					BEGIN
						OPEN	:sys_cursor	FOR
            SELECT FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
     FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  /*** Ver 3.1 ***/
     FOD_FC_FLAG,                             /*** Ver 3.1 ***/
     FOD_SPN_FLG,                             /*** Ver 3.2 ***/
     FOD_TRD_VAL,                               /*** Ver 4.1 ***/
     FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
     FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
     FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
     FOD_ESP_ID,                                 /*** Ver 6.4 ***/
     FOD_1CLICK_FLG,             /*** ver 6.9 **/
     FOD_SOURCE_FLG,
		 NVL(FTQ_LST_TRD_PRC,0),
     NVL(FTQ_TRAIL_FLG,'N'),
		 FXB_RQST_TM     /** Added in Ver 8.8 by Vishal **/
            FROM
            (
              SELECT    FOD_CLM_MTCH_ACCNT,
                        FOD_ORDR_RFRNC,
                        FOD_PIPE_ID,
                        FOD_XCHNG_CD,
                        FOD_PRDCT_TYP,
                        FOD_INDSTK,
                        FOD_UNDRLYNG,
     FOD_EXPRY_DT,
     FOD_EXER_TYP,
     FOD_OPT_TYP,
     FOD_STRK_PRC,
     FOD_ORDR_FLW,
     FOD_LMT_MRKT_SL_FLG,
     FOD_DSCLSD_QTY,
     FOD_ORDR_TOT_QTY,
     FOD_LMT_RT,
     FOD_STP_LSS_TGR,
     FOD_ORDR_TYPE,
     FOD_ORDR_VALID_DT,
     FOD_TRD_DT,
     FOD_ORDR_STTS,
     FOD_EXEC_QTY,
     FOD_CNCL_QTY,
     FOD_EXPRD_QTY,
     FOD_SPRD_ORDR_REF,
     FOD_SETTLOR,
     FOD_MDFCTN_CNTR,
     FOD_ACK_NMBR,
     FOD_SPL_FLAG,
     FOD_REMARKS,
     FOD_CHANNEL,
     FOD_BP_ID,
     FOD_AMT_BLCKD,  /*** Ver 3.1 ***/
     FOD_FC_FLAG,                             /*** Ver 3.1 ***/
     FOD_SPN_FLG,                             /*** Ver 3.2 ***/
     FOD_TRD_VAL,                               /*** Ver 4.1 ***/
     FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
     FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
     FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
     FOD_FC_FLAG1,
     FOD_PRCIMPV_FLG,                          /*** Ver 5.5 ***/
     FOD_ESP_ID,                                 /*** Ver 6.4 ***/
     FOD_1CLICK_FLG,             /*** ver 6.9 **/
     FOD_SOURCE_FLG,
     ROWNUM REC_INDEX,
		 FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
   FROM
   (   
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                      
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
										DECODE(FOD_SOURCE_FLG,'F',DECODE(FOD_PRDCT_TYP,'O',' ',FOD_FC_FLAG),FOD_FC_FLAG) FOD_FC_FLAG1,
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,          
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,											
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,           
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/           
						FROM		FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/		
						WHERE		FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
            AND     FOD_XCHNG_CD       LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8**/
						AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND			FOD_ORDR_STTS			 <>		'Y'											
						AND			FOD_IS_FLG				 LIKE :c_is_flg
						AND     NVL(FOD_ESP_ID,'*')		 LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** Ver 4.6 ***/
                     )
						AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
			  	  AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
						UNION ALL
						SELECT  FOD_CLM_MTCH_ACCNT FOD_CLM_MTCH_ACCNT, 
										FOD_ORDR_RFRNC FOD_ORDR_RFRNC,
										FOD_PIPE_ID FOD_PIPE_ID, 
										FOD_XCHNG_CD FOD_XCHNG_CD, 
										FOD_PRDCT_TYP FOD_PRDCT_TYP,
										FOD_INDSTK FOD_INDSTK,
										FOD_UNDRLYNG FOD_UNDRLYNG, 
										to_char ( FOD_EXPRY_DT, 'dd-Mon-yyyy' ) FOD_EXPRY_DT, 
										FOD_EXER_TYP FOD_EXER_TYP, 
										FOD_OPT_TYP FOD_OPT_TYP, 
										FOD_STRK_PRC FOD_STRK_PRC,
										FOD_ORDR_FLW FOD_ORDR_FLW, 
										FOD_LMT_MRKT_SL_FLG FOD_LMT_MRKT_SL_FLG, 
										NVL( FOD_DSCLSD_QTY, 0 ) FOD_DSCLSD_QTY, 
										FOD_ORDR_TOT_QTY FOD_ORDR_TOT_QTY, 
										NVL( FOD_LMT_RT, 0 ) FOD_LMT_RT, 
										NVL( FOD_STP_LSS_TGR, 0 ) FOD_STP_LSS_TGR, 
										FOD_ORDR_TYPE FOD_ORDR_TYPE, 
										to_char ( FOD_ORDR_VALID_DT, 'dd-Mon-yyyy' ) FOD_ORDR_VALID_DT, 
										to_char ( FOD_TRD_DT, 'dd-Mon-yyyy' ) FOD_TRD_DT, 
										FOD_ORDR_STTS FOD_ORDR_STTS,
										FOD_EXEC_QTY FOD_EXEC_QTY, 
										FOD_CNCL_QTY FOD_CNCL_QTY, 
										FOD_EXPRD_QTY FOD_EXPRD_QTY, 
										NVL( FOD_SPRD_ORDR_REF, ' ' ) FOD_SPRD_ORDR_REF,
										NVL( FOD_SETTLOR, ' ' ) FOD_SETTLOR,
										FOD_MDFCTN_CNTR FOD_MDFCTN_CNTR,
										NVL( FOD_ACK_NMBR, ' ' ) FOD_ACK_NMBR,
										FOD_SPL_FLAG FOD_SPL_FLAG,
										NVL( FOD_REMARKS, ' ' ) FOD_REMARKS,
										NVL( FOD_CHANNEL,'*') FOD_CHANNEL,                    
										NVL( FOD_BP_ID,' ') FOD_BP_ID,
										NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0) FOD_AMT_BLCKD,	/*** Ver 3.1 ***/
										NVL(FOD_FC_FLAG,' ') FOD_FC_FLAG,															/*** Ver 3.1 ***/
										NVL(FOD_SPN_FLG,'N') FOD_SPN_FLG,															/*** Ver 3.2 ***/
                    NVL(FOD_TRD_VAL,0) FOD_TRD_VAL,                               /*** Ver 4.1 ***/
                    NVL(FOD_TRD_BRKG,0) FOD_TRD_BRKG,                              /*** Ver 4.1 ***/
                    NVL(FOD_CNTRCTNT_NMBR,'*') FOD_CNTRCTNT_NMBR,                        /*** Ver 4.1 ***/
                    FOD_SLTP_ORDR_RFRNC FOD_SLTP_ORDR_RFRNC,                       
                    FOD_FC_FLAG FOD_FC_FLAG1,                              
										NVL( FOD_PRCIMPV_FLG, 'N') FOD_PRCIMPV_FLG,              
										NVL(FOD_ESP_ID,'*') FOD_ESP_ID,										
										 NVL(FOD_1CLICK_FLG,'N') FOD_1CLICK_FLG,             
                    NVL(FOD_SOURCE_FLG, '*') FOD_SOURCE_FLG,
										FXB_RQST_TM FXB_RQST_TM   /** Added in Ver 8.8 by Vishal **/            
						FROM		FOD_FO_ORDR_DTLS_HSTRY,FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/		
						WHERE		FOD_CLM_MTCH_ACCNT =		:c_mtch_accnt_no
            AND      FOD_XCHNG_CD      LIKE :c_exchange_cd  /*** Ver 2.8 ***/ /*** Ver 7.9 LIKE to = ***/ /*LIKE added in Ver 8.8**/
						AND			FOD_PRDCT_TYP			 LIKE :c_product_typ
						AND			FOD_ORDR_STTS			 LIKE :c_ordr_stts 
						AND			FOD_ORDR_STTS			 <>		'Y'											
						AND			FOD_IS_FLG				 LIKE :c_is_flg     
						AND     NVL(FOD_ESP_ID,'*')	 LIKE :c_ven_id     /*** Ver 6.4 ***/
            AND
                     (
                      ( FOD_ORDR_RFRNC        >=    :c_min_ref_num
                        AND   FOD_ORDR_RFRNC  <     :c_max_ref_num ) OR
                      ( FOD_ORDR_RFRNC        <     :c_min_ref_num
                        AND FOD_TRD_DT >=    to_date(:c_frm_dt,'dd-mon-yyyy') )  /*** ver 4.6 ***/
                     )
            AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
				    AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
           /** ORDER BY 1 ,2 DESC **/ /** Commented in Ver 8.8 **/
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC /** Added in Ver 8.8 **/
          )
           ),FTQ_FO_TRD_QT
            WHERE FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+)
          AND REC_INDEX >=:l_start_rec_no
				  AND    REC_INDEX <=:l_end_rec_no
						ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/ 
	
        END;
				END-EXEC;
			}
			/*** Ver 2.6 ends here ***/
    }
		else if ( c_opr_typ == EXCHNG_ACK_AND_PIPE_ID_IP )
		{  
        if ( DEBUG_MSG_LVL_5 )  /*** Ver 5.2 ***/
        {
					fn_userlog(c_ServiceName, "EXCHNG_ACK_AND_PIPE_ID_IP Commented by Sangeet");
		    }
    } 
		

		/****************** 2.7 Order details Starts *******************/ 

		else if ( c_opr_typ == ORDER_REF_IP )
		{
					SETLEN( c_ordr_ref );
          
          if ( DEBUG_MSG_LVL_1 )  /*** Ver 5.2 ***/
          {				
	        	fn_userlog(c_ServiceName, "INSIDE ORDER_REF_IP" );
						fn_userlog(c_ServiceName, "c_ordr_ref = :%s:", c_ordr_ref.arr);
          }

					li_rec_main_exists = 0;

    		  EXEC SQL
        	SELECT    1
          INTO    :li_rec_main_exists
        	FROM      dual
        	WHERE     EXISTS
        	(
        		SELECT    1
          	FROM    fod_fo_ordr_dtls
         		WHERE   fod_ordr_rfrnc     = :c_ordr_ref
        );

	 		  if ( DEBUG_MSG_LVL_5 )  /*** Ver 5.2 ***/
        {
        	fn_userlog(c_ServiceName, "li_rec_main_exists = :%ld:", li_rec_main_exists);
        }

    	 if ( ( SQLCODE !=0 ) && ( SQLCODE != NO_DATA_FOUND ) )
    	 {
							fn_errlog( c_ServiceName, "S31345", SQLMSG, c_errmsg  );
							Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
							tpcommit(0);
							tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
       }
	

			if ( li_rec_main_exists == 1 )
      {
      		EXEC SQL  EXECUTE
          BEGIN
          OPEN  :sys_cursor FOR
          SELECT  fod_clm_mtch_accnt,
                      fod_ordr_rfrnc,
                      fod_pipe_id,
                      fod_xchng_cd,
                      fod_prdct_typ,
                      fod_indstk,
                      fod_undrlyng,
                      to_char ( fod_expry_dt, 'dd-Mon-yyyy' ),
                      fod_exer_typ,
                      fod_opt_typ,
                      fod_strk_prc,
                      fod_ordr_flw,
                      fod_lmt_mrkt_sl_flg,
                      NVL( fod_dsclsd_qty, 0 ),
                      fod_ordr_tot_qty,
                      NVL( fod_lmt_rt, 0 ),
                      NVL( fod_stp_lss_tgr, 0 ),
                      fod_ordr_type,
                      to_char ( fod_ordr_valid_dt, 'dd-Mon-yyyy' ),
                      to_char ( fod_trd_dt, 'dd-Mon-yyyy' ),
                      fod_ordr_stts,
                      fod_exec_qty,
                      fod_cncl_qty,
                      fod_exprd_qty,
                      NVL( fod_sprd_ordr_ref, ' ' ),
                      NVL( fod_settlor, ' ' ),
                      fod_mdfctn_cntr,
											NVL( fod_ack_nmbr, ' ' ),
                      fod_spl_flag,
                      NVL(fod_remarks,' '),
                      NVL( fod_channel,'*'),
                      NVL( fod_bp_id,' '),
											NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0),	/*** Ver 3.1 ***/
											NVL(FOD_FC_FLAG,' '),															/*** Ver 3.1 ***/
											NVL(FOD_SPN_FLG,'N'),															/*** Ver 3.2 ***/
                    	NVL(FOD_TRD_VAL,0),                               /*** Ver 4.1 ***/
                    	NVL(FOD_TRD_BRKG,0),                              /*** Ver 4.1 ***/
                    	NVL(FOD_CNTRCTNT_NMBR,'*'),                        /*** Ver 4.1 ***/
                      FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                      FOD_FC_FLAG,                                         /*** Ver 4.7 ***/
											NVL( FOD_PRCIMPV_FLG, 'N'),                          /*** Ver 5.5 ***/
											NVL(FOD_ESP_ID,'*'),																	/*** Ver 6.4 ***/
											 NVL(FOD_1CLICK_FLG,'N'),             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*'),                            /*** Ver 7.7 ***/
                    NVL(FTQ_LST_TRD_PRC,0),									/*** Ver 8.6 Nikhil ***/
                NVL(FTQ_TRAIL_FLG,'N')										/*** Ver 8.6 Nikhil ***/
                FROM  fod_fo_ordr_dtls,FTQ_FO_TRD_QT      /*** Ver 8.6 Nikhil ***/
                WHERE fod_ordr_rfrnc = :c_ordr_ref
					 	AND FOD_XCHNG_CD = FTQ_XCHNG_CD(+)              /*** Ver 8.6 Nikhil ***/
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+);


								END;
							END-EXEC;

				}
				else
    		{
							EXEC SQL  EXECUTE
							BEGIN
              OPEN  :sys_cursor FOR
              SELECT  fod_clm_mtch_accnt,
                      fod_ordr_rfrnc,
                      fod_pipe_id,
                      fod_xchng_cd,
                      fod_prdct_typ,
                      fod_indstk,
                      fod_undrlyng,
                      to_char ( fod_expry_dt, 'dd-Mon-yyyy' ),
                      fod_exer_typ,
                      fod_opt_typ,
                      fod_strk_prc,
                      fod_ordr_flw,
                      fod_lmt_mrkt_sl_flg,
                      NVL( fod_dsclsd_qty, 0 ),
                      fod_ordr_tot_qty,
                      NVL( fod_lmt_rt, 0 ),
                      NVL( fod_stp_lss_tgr, 0 ),
                      fod_ordr_type,
                      to_char ( fod_ordr_valid_dt, 'dd-Mon-yyyy' ),
                      to_char ( fod_trd_dt, 'dd-Mon-yyyy' ),
                      fod_ordr_stts,
                      fod_exec_qty,
                      fod_cncl_qty,
                      fod_exprd_qty,
                      NVL( fod_sprd_ordr_ref, ' ' ),
                      NVL( fod_settlor, ' ' ),
                      fod_mdfctn_cntr,
											NVL( fod_ack_nmbr, ' ' ),
                      fod_spl_flag,
                      NVL(fod_remarks,' '),
                      NVL( fod_channel,'*'),
                      NVL( fod_bp_id,' '),
											NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0),	/*** Ver 3.1 ***/
											NVL(FOD_FC_FLAG,' '),															/*** Ver 3.1 ***/
											NVL(FOD_SPN_FLG,'N'),															/*** Ver 3.2 ***/
                    	NVL(FOD_TRD_VAL,0),                               /*** Ver 4.1 ***/
                    	NVL(FOD_TRD_BRKG,0),                              /*** Ver 4.1 ***/
                    	NVL(FOD_CNTRCTNT_NMBR,'*'),                        /*** Ver 4.1 ***/
                      FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                      FOD_FC_FLAG,                                         /*** Ver 4.7 ***/
											NVL( FOD_PRCIMPV_FLG, 'N'),                          /*** Ver 5.5 ***/
											NVL(FOD_ESP_ID,'*'),																	/*** Ver 6.4 ***/
											 NVL(FOD_1CLICK_FLG,'N'),             /*** ver 6.9 ***/
                    NVL(FOD_SOURCE_FLG, '*'),                            /*** Ver 7.7 ***/
											 NVL(FTQ_LST_TRD_PRC,0),                  /*** Ver 8.6 Nikhil ***/
                NVL(FTQ_TRAIL_FLG,'N')                    /*** Ver 8.6 Nikhil ***/
                FROM  fod_fo_ordr_dtls_hstry,FTQ_FO_TRD_QT      /*** Ver 8.6 Nikhil ***/
                WHERE fod_ordr_rfrnc = :c_ordr_ref
						AND		FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+);
            END;
        END-EXEC;
      }
		} /**end if **/
		else
		{
			strcpy ( c_errmsg, "Invalid operation type" );
			fn_userlog( c_ServiceName,"Invalid operation type" );
			EXEC SQL FREE :sys_cursor;
			Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
			tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
		}
	} /* End for single Match Id. Ver 1.4 */

	if ( SQLCODE != 0 )
	{
		fn_errlog( c_ServiceName, "S31350", SQLMSG, c_errmsg  );
    EXEC SQL FREE :sys_cursor;
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
	}
	/** tpfree ( ( char * )ptr_fml_obuf);	** Commented for Ver 4.8 **/						/*SANGEET*/
	ptr_fml_obuf = (FBFR32 *)tpalloc( "FML32", NULL, MIN_FML_BUF_LEN * BUF_MULTIPLY );

  if ( ptr_fml_obuf == NULL )
  {
    fn_errlog( c_ServiceName, "S31355", TPMSG, c_errmsg  );
    EXEC SQL CLOSE :sys_cursor;
    EXEC SQL FREE :sys_cursor;
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }

	/********** Commented for Ver 4.2 *******
  ptr_st_orderbook = ( struct vw_orderbook * ) tpalloc ( "VIEW32",
                                                         "vw_orderbook",
                                               sizeof ( struct vw_orderbook ) );
	********** Commented end for Ver 4.2 *******/

	/**** Added for Ver 4.2 ****/
	ptr_st_orderbook = malloc(sizeof(struct vw_orderbook));
	/** End for Ver 4.2 ***/

  if ( ptr_st_orderbook == NULL )
  {
    fn_errlog( c_ServiceName, "S31360", TPMSG, c_errmsg  );
		EXEC SQL CLOSE :sys_cursor;
    EXEC SQL FREE :sys_cursor;
		tpfree ( ( char * )ptr_fml_obuf);
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }

  memset ( ptr_st_orderbook, 0, sizeof ( struct vw_orderbook ) );

	strcpy ( ptr_st_orderbook->c_user_id, st_usr_prfl.c_user_id );
	ptr_st_orderbook->c_oprn_typ = c_opr_typ; 
	strcpy ( ptr_st_orderbook->c_cln_mtch_accnt, c_mtch_accnt_no );

  MEMSET(c_sltp_ord_rfrnc_prev); /* ver 8.4 */
  c_spl_flg_prev='\0';           /* ver 8.4 */
  MEMSET(c_ordr_rfrnc_prev);     /* ver 8.4 */
  MEMSET(c_cln_mtch_accnt_prev); /* ver 8.4 */
  c_last_leg ='\0';                /* ver 8.4 */ 
  i_first_order=0;                 /* Ver 8.4 */
  i_counter = 1 ;

	for ( ; ; )
	{

		MEMSET(c_esp_id);	/*** Ver 6.4 ***/
		MEMSET(c_esp_nm);	/*** Ver 6.4 ***/
   c_sltp_trail_flag = '\0';    /*** Ver 8.6 Nikhil ***/
   l_ltp_prc=0;                /*** Ver 8.6 Nikhil ***/

		EXEC SQL FETCH :sys_cursor
							INTO :ptr_st_orderbook->c_cln_mtch_accnt, /* Ver 1.4 */
									 :ptr_st_orderbook->c_ordr_rfrnc,
									 :ptr_st_orderbook->c_pipe_id,
									 :ptr_st_orderbook->c_xchng_cd,  
									 :ptr_st_orderbook->c_prd_typ,  
									 :ptr_st_orderbook->c_ctgry_indstk,  
									 :ptr_st_orderbook->c_undrlyng,  
									 :c_exp_date,  
									 :ptr_st_orderbook->c_exrc_typ,  
									 :ptr_st_orderbook->c_opt_typ,  
									 :ptr_st_orderbook->l_strike_prc,  
									 :ptr_st_orderbook->c_ordr_flw,  
									 :ptr_st_orderbook->c_slm_flg,  
									 :ptr_st_orderbook->l_dsclsd_qty,  
									 :ptr_st_orderbook->l_ord_tot_qty,  
									 :ptr_st_orderbook->l_ord_lmt_rt,  
									 :ptr_st_orderbook->l_stp_lss_tgr,  
									 :ptr_st_orderbook->c_ord_typ,  
									 :c_valid_date,  
									 :c_trd_date,  
									 :ptr_st_orderbook->c_ordr_stts,  
									 :ptr_st_orderbook->l_exctd_qty,  
									 :ptr_st_orderbook->l_can_qty,  
									 :ptr_st_orderbook->l_exprd_qty,  
									 :ptr_st_orderbook->c_sprd_ord_rfrnc,  
									 :ptr_st_orderbook->c_settlor,
									 :ptr_st_orderbook->l_mdfctn_cntr,
									 :ptr_st_orderbook->c_xchng_ack,
                   :ptr_st_orderbook->c_spl_flg,
                   :c_remarks,
									 :ptr_st_orderbook->c_channel,
									 :ptr_st_orderbook->c_bp_id,
									 :d_mrgn_blk,												/*** Ver 3.1 ***/
									 :c_fc_flg, 												/*** Ver 3.1 ***/
									 :c_spn_flg,												/*** Ver 3.2 ***/
									 :d_trd_val,												/*** Ver 4.1 ***/
									 :l_brkg_val,												/*** Ver 4.1 ***/	
									 :c_cntrct_num,											/*** Ver 4.1 ***/
                   :c_tag_ordr_rfrnce,                    /** Ver 4.7 **/
                   :c_fc_flg,                          /* ver 4.7 */
									 :c_prcimpv_flg,                    /** Ver 5.5 **/	
									 :c_esp_id,														/*** Ver 6.4 ***/
									 :c_1clk_flg,														/*** ver 6.9 ***/	
									 :c_src_flg,                          /*** Ver 7.7 ***/
									 :l_ltp_prc,                /*** Ver 8.6 Nikhil ***/
                	 :c_sltp_trail_flag;        /*** Ver 8.6 Nikhil ***/
 
		if ( SQLCODE != 0 )
		{
			if ( SQLCODE == NO_DATA_FOUND )
			{
        if( DEBUG_MSG_LVL_2 )
        {
         fn_userlog(c_ServiceName,"c_spl prev :%c: SLTP Prev:%s: OrdRef :%s: ",c_spl_flg_prev,c_sltp_ord_rfrnc_prev,c_ordr_rfrnc_prev);
        }

        if( c_spl_flg_prev == 'O' ) /** Ver 8.4 Rollover Spread order **/
        {
          if( strcmp(c_ordr_rfrnc_prev,c_sltp_ord_rfrnc_prev)> 0 )
          {
            EXEC SQL
            SELECT    fod_clm_mtch_accnt,
                      fod_ordr_rfrnc,
                      fod_pipe_id,
                      fod_xchng_cd,
                      fod_prdct_typ,
                      fod_indstk,
                      fod_undrlyng,
                      to_char ( fod_expry_dt, 'dd-Mon-yyyy' ),
                      fod_exer_typ,
                      fod_opt_typ,
                      fod_strk_prc,
                      fod_ordr_flw,
                      fod_lmt_mrkt_sl_flg,
                      NVL( fod_dsclsd_qty, 0 ),
                      fod_ordr_tot_qty,
                      NVL( fod_lmt_rt, 0 ),
                      NVL( fod_stp_lss_tgr, 0 ),
                      fod_ordr_type,
                      to_char ( fod_ordr_valid_dt, 'dd-Mon-yyyy' ),
                      to_char ( fod_trd_dt, 'dd-Mon-yyyy' ),
                      fod_ordr_stts,
                      fod_exec_qty,
                      fod_cncl_qty,
                      fod_exprd_qty,
                      NVL( fod_sprd_ordr_ref, ' ' ),
                      NVL( fod_settlor, ' ' ),
                      fod_mdfctn_cntr,
                      NVL( fod_ack_nmbr, ' ' ),
                      fod_spl_flag,
                      NVL(fod_remarks,' '),
                      NVL( fod_channel,'*'),
                      NVL( fod_bp_id,' '),
                      NVL(FOD_AMT_BLCKD,0) + NVL(FOD_LSS_AMT_BLCKD,0),  /*** Ver 3.1 ***/
                      NVL(FOD_FC_FLAG,' '),                             /*** Ver 3.1 ***/
                      NVL(FOD_SPN_FLG,'N'),                             /*** Ver 3.2 ***/
                      NVL(FOD_TRD_VAL,0),                               /*** Ver 4.1 ***/
                      NVL(FOD_TRD_BRKG,0),                              /*** Ver 4.1 ***/
                      NVL(FOD_CNTRCTNT_NMBR,'*'),                        /*** Ver 4.1 ***/
                      FOD_SLTP_ORDR_RFRNC,                                /*** Ver 4.7 ***/
                      FOD_FC_FLAG,                                         /*** Ver 4.7 ***/
                      NVL( FOD_PRCIMPV_FLG, 'N'),                          /*** Ver 5.5 ***/
                      NVL(FOD_ESP_ID,'*'),                                  /*** Ver 6.4 ***/
                      NVL(FOD_1CLICK_FLG,'N'),             /*** ver 6.9 ***/
                      NVL(FOD_SOURCE_FLG, '*'),
                      NVL(FTQ_LST_TRD_PRC,0),								/*** Ver 8.6 Nikhil ***/
                      NVL(FTQ_TRAIL_FLG,'N')   							/*** Ver 8.6 Nikhil ***/
                INTO  :ptr_st_orderbook->c_cln_mtch_accnt, /* Ver 1.4 */
                   :ptr_st_orderbook->c_ordr_rfrnc,
                   :ptr_st_orderbook->c_pipe_id,
                   :ptr_st_orderbook->c_xchng_cd,
                   :ptr_st_orderbook->c_prd_typ,
                   :ptr_st_orderbook->c_ctgry_indstk,
                   :ptr_st_orderbook->c_undrlyng,
                   :c_exp_date,
                   :ptr_st_orderbook->c_exrc_typ,
                   :ptr_st_orderbook->c_opt_typ,
                   :ptr_st_orderbook->l_strike_prc,
                   :ptr_st_orderbook->c_ordr_flw,
                   :ptr_st_orderbook->c_slm_flg,
                   :ptr_st_orderbook->l_dsclsd_qty,
                   :ptr_st_orderbook->l_ord_tot_qty,
                   :ptr_st_orderbook->l_ord_lmt_rt,
                   :ptr_st_orderbook->l_stp_lss_tgr,
                   :ptr_st_orderbook->c_ord_typ,
                   :c_valid_date,
                   :c_trd_date,
                   :ptr_st_orderbook->c_ordr_stts,
                   :ptr_st_orderbook->l_exctd_qty,
                   :ptr_st_orderbook->l_can_qty,
                   :ptr_st_orderbook->l_exprd_qty,
                   :ptr_st_orderbook->c_sprd_ord_rfrnc,
                   :ptr_st_orderbook->c_settlor,
                   :ptr_st_orderbook->l_mdfctn_cntr,
                   :ptr_st_orderbook->c_xchng_ack,
                   :ptr_st_orderbook->c_spl_flg,
                   :c_remarks,
                   :ptr_st_orderbook->c_channel,
                   :ptr_st_orderbook->c_bp_id,
                   :d_mrgn_blk,                       /*** Ver 3.1 ***/
                   :c_fc_flg,                         /*** Ver 3.1 ***/
                   :c_spn_flg,                        /*** Ver 3.2 ***/
                   :d_trd_val,                        /*** Ver 4.1 ***/
                   :l_brkg_val,                       /*** Ver 4.1 ***/
                   :c_cntrct_num,                     /*** Ver 4.1 ***/
                   :c_tag_ordr_rfrnce,                    /** Ver 4.7 **/
                   :c_fc_flg,                          /* ver 4.7 */
                   :c_prcimpv_flg,                    /** Ver 5.5 **/
                   :c_esp_id,                           /*** Ver 6.4 ***/
                   :c_1clk_flg,                           /*** ver 6.9 ***/
                   :c_src_flg,
									 :l_ltp_prc,													/*** Ver 8.6 Nikhil ***/
                	:c_sltp_trail_flag 										/*** Ver 8.6 Nikhil ***/
                FROM  fod_fo_ordr_dtls,FTQ_FO_TRD_QT      /*** Ver 8.6 Nikhil ***/
                WHERE fod_ordr_rfrnc =:c_sltp_ord_rfrnc_prev
						AND		FOD_XCHNG_CD = FTQ_XCHNG_CD(+)
            AND  decode(FOD_PRDCT_TYP,'P','F','U','F','I','O',FOD_PRDCT_TYP) = FTQ_PRDCT_TYP(+)
            AND  FOD_UNDRLYNG  = FTQ_UNDRLYNG(+)
            AND  FOD_EXPRY_DT  = FTQ_EXPRY_DT(+)
            AND  FOD_OPT_TYP   = FTQ_OPT_TYP(+)
            AND  FOD_STRK_PRC  = FTQ_STRK_PRC(+)
            AND  FOD_EXER_TYP  = FTQ_EXER_TYP(+);
            if ( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND)
            {
              fn_errlog( c_ServiceName, "S31365", SQLMSG, c_errmsg  );
              EXEC SQL CLOSE :sys_cursor;
              EXEC SQL FREE :sys_cursor;
              tpfree ( ( char * ) ptr_fml_obuf );
              free((char *)ptr_st_orderbook);
              Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
              tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
            }
            if( SQLCODE == NO_DATA_FOUND )
            {
              break;
            }
            c_last_leg='Y'; 
          }
          else
          {
             break;
          }
        }
        else
        {
				  break;
        }
			}
			else
			{
				fn_errlog( c_ServiceName, "S31370", SQLMSG, c_errmsg  );
      	EXEC SQL CLOSE :sys_cursor;
      	EXEC SQL FREE :sys_cursor;
      	tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}
		}
		rtrim(c_cntrct_num);
		SETLEN(c_esp_id); /*** Ver 6.4 ***/
		SETNULL(c_esp_id); /*** Ver 6.4 ***/
  
    /**** Ver 8.4 starts ****/
    if( i_first_order == 0 )
    {
      if( ptr_st_orderbook->c_spl_flg == 'O' )  /** Spread Rollover order **/
      {
        if( strcmp(ptr_st_orderbook->c_ordr_rfrnc,c_tag_ordr_rfrnce)< 0 ) /** If first order on page is 2nd spread order leg then dont display as same is displayed on prevous page ***/
        {
           continue;
        } 
      } 
    }
    i_first_order=i_first_order+1;

    strcpy(c_sltp_ord_rfrnc_prev,c_tag_ordr_rfrnce);
    strcpy(c_ordr_rfrnc_prev,ptr_st_orderbook->c_ordr_rfrnc);
    strcpy(c_cln_mtch_accnt_prev,ptr_st_orderbook->c_cln_mtch_accnt);
    c_spl_flg_prev = ptr_st_orderbook->c_spl_flg;
    /**** Ver 8.4 Ends here ****/
 
    if ( DEBUG_MSG_LVL_3 )  /*** Ver 5.2 ***/
    {
			fn_userlog(c_ServiceName,"1Clk_flag :%c:",c_1clk_flg);			/*** ver 6.9 ****/         
			fn_userlog(c_ServiceName,"SPAN FLAG :%c:",c_spn_flg);																							/*** Ver 3.2 ***/
			fn_userlog(c_ServiceName,"ptr_st_orderbook->c_ordr_rfrnc :%s:",ptr_st_orderbook->c_ordr_rfrnc);		/*** Ver 3.2 ***/
    }
 
    /*** Commented in Ver 4.5 ***
    fn_userlog(c_ServiceName,"ptr_st_orderbook->c_ordr_rfrnc",ptr_st_orderbook->c_ordr_rfrnc);
    ***/
	  
    if ( DEBUG_MSG_LVL_3 )  /*** Ver 5.2 ***/
    {
  		fn_userlog(c_ServiceName,"Contract Note Number Is :%s:",c_cntrct_num);
    }

    /*** Ver 3.8 ** Starts ***/

    if( (ptr_st_orderbook->c_spl_flg == IMTM_SYS_SQUAREOFF ) || (ptr_st_orderbook->c_spl_flg == LMTNEG_SYS_SQUAREOFF ) )
    {
      ptr_st_orderbook->c_spl_flg = 'S';
    }

    /*** Ver 3.8 ** Ends ***/

		/** Ver 3.4 moved with adding Selective IF Condition ***/

	 //c_sltp_trail_flag = '\0';   /*** Ver 5.5 ***/ 

  /*** comment in ver 8.4 nikhil ***/

	/**** if ( strcmp(ptr_st_orderbook->c_channel,"WE4") == 0 || strcmp(ptr_st_orderbook->c_channel,"WE6") == 0 ||
 				strcmp(ptr_st_orderbook->c_channel,"WE7") == 0 || strcmp(ptr_st_orderbook->c_channel,"WE8") == 0 || 
        strcmp(ptr_st_orderbook->c_channel,"WE9") == 0 || strcmp(ptr_st_orderbook->c_channel,"WEH") == 0 ||
				st_usr_prfl.l_session_id != 0 )  *** Ver 4.3 IF Condition Uncommented and WEH Channel and Session ID added ***
    {
    	EXEC SQL
      	SELECT  NVL(FTQ_LST_TRD_PRC,0),
								NVL(FTQ_TRAIL_FLG,'N')          *** Added in Ver 5.5 ***
      	INTO    :l_ltp_prc,
								:c_sltp_trail_flag              *** Added in Ver 5.5 ***
      	FROM    FTQ_FO_TRD_QT
      	WHERE   FTQ_XCHNG_CD  = :ptr_st_orderbook->c_xchng_cd                            *** Ver 2.6 ***
				AND     FTQ_PRDCT_TYP = decode(:ptr_st_orderbook->c_prd_typ,'P','F','U','F','I','O',:ptr_st_orderbook->c_prd_typ) ***  Ver 3.7***   *** 'I' added in Ver 4.0 ***
      	AND     FTQ_UNDRLYNG  = :ptr_st_orderbook->c_undrlyng
      	AND     FTQ_EXPRY_DT  = :c_exp_date
      	AND     FTQ_EXER_TYP  = :ptr_st_orderbook->c_exrc_typ
      	AND     FTQ_OPT_TYP   = :ptr_st_orderbook->c_opt_typ
      	AND     FTQ_STRK_PRC  = :ptr_st_orderbook->l_strike_prc;

    	if ( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND)
    	{
      	fn_errlog( c_ServiceName, "S31375", SQLMSG, c_errmsg  );
      	EXEC SQL CLOSE :sys_cursor;
      	EXEC SQL FREE :sys_cursor;
      	tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);		** Ver 4.8 **
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    	} }****/
 
     /*** comment in ver 8.4 nikhil ***/

    	if( DEBUG_MSG_LVL_3 )
    	{
      	fn_userlog(c_ServiceName,"l_ltp_prc:%ld:",l_ltp_prc);
    	}

    	if ( Fadd32 ( ptr_fml_obuf,FFO_LST_TRD_PRC ,( char *)&l_ltp_prc, 0 ) == -1 )
    	{
      	fn_errlog( c_ServiceName, "S31380",FMLMSG,c_errmsg);
      	EXEC SQL CLOSE :sys_cursor;
      	EXEC SQL FREE :sys_cursor;
      	tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      	strcpy(c_errmsg,"Problem in adding Open Quantity");
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     	}

	/** Ver 3.4 ends **/

		/* Ver 1.3 */
		/** Ver 2.7 WE6 added ***/

 
		if(ptr_st_orderbook->c_channel[0] == '*'|| strcmp(ptr_st_orderbook->c_channel,"WE1") == 0 ||
       strcmp(ptr_st_orderbook->c_channel,"WE4") == 0 || strcmp(ptr_st_orderbook->c_channel,"WE6") == 0 ||
       strcmp(ptr_st_orderbook->c_channel,"WE7") == 0 || strcmp(ptr_st_orderbook->c_channel,"WE8") == 0 ||
       strcmp(ptr_st_orderbook->c_channel,"WE9") == 0 || strcmp(ptr_st_orderbook->c_channel,"WEH") == 0 ||
       strcmp(ptr_st_orderbook->c_channel,"WEN") == 0 || strcmp(ptr_st_orderbook->c_channel,"WEO") == 0 ||
       strcmp(ptr_st_orderbook->c_channel,"WEP") == 0 || strcmp(ptr_st_orderbook->c_channel,"WED") == 0 ) /**Ver 2.5***/ /** Ver 2.9 WE7 & WE8 added **/  /*** Ver 3.3  WE9 Added ***/ /** Ver 4.1 WEH added **/ /*** WEN,WEO and WEP added in Ver 5.1 ***/ /*** channel WED added in Ver 5.7 ***/ /*** API channel WE4 existing Ver 6.4 ***/
		{
				strcpy(ptr_st_orderbook->c_channel,"WEB");
		}


		if((strcmp(ptr_st_orderbook->c_channel,"CN1")== 0)||(strcmp(ptr_st_orderbook->c_channel,"CN2")== 0)) /*V1.2 Super User*/   /***	Ver	3.5	CN2 Handling Introduced	***/ 
		{
				strcpy(ptr_st_orderbook->c_channel,"CNT");
		}

    /*** Ver 7.2 Starts Here ***/
    if ((strcmp(c_esp_id.arr,"*") != 0) && (strcmp(ptr_st_orderbook->c_ctcl_id,"5555555555555") != 0) &&
                                           (strcmp(ptr_st_orderbook->c_ctcl_id,"333333333333") != 0)
       )
    { 
      strcpy(ptr_st_orderbook->c_channel,"API");    
    }
    /*** Ver 7.2 Ends Here ***/ 

		SETNULL(c_exp_date);
		SETNULL(c_valid_date);
		SETNULL(c_trd_date);

		strcpy ( ptr_st_orderbook->c_expry_dt, ( char * ) c_exp_date.arr );
		strcpy ( ptr_st_orderbook->c_valid_dt, ( char * ) c_valid_date.arr );
		strcpy ( ptr_st_orderbook->c_trd_dt,   ( char * ) c_trd_date.arr );

    l_bufferlength = 	sizeof( struct vw_orderbook ) 
                   +  sizeof( c_remarks ) 
                   +  (sizeof( c_mod_can_flg ) * 2)
									 +	sizeof(c_dbc_channel)												/***	ver 1.6 DL Revamp ***/
									 +	sizeof(l_open_qty)													/***  ver 1.6 DL Revamp ***/
									 +	sizeof(d_mrgn_blk)													/*** Ver 3.1 ***/
									 +	256,
									 +	sizeof(c_1clk_flg);			/*** ver 6.9  ***/
   /**  ver 1.6    +  sizeof(c_request_tm);          ******/

    if ( Fneeded32( 1, l_bufferlength ) > Funused32( ptr_fml_obuf ) )
    {
      i_counter++;
      /* Ver 1.9 Starts */
			/*	ptr_fml_obuf = ( FBFR32 *)tprealloc( (char *)ptr_fml_obuf,
                       (i_counter * l_bufferlength * BUF_MULTIPLY) ); */
				ptr_fml_obuf = ( FBFR32 *)tprealloc( (char *)ptr_fml_obuf,
											 (Fsizeof32(ptr_fml_obuf) + (i_counter *l_bufferlength )));

			/* Ver 1.9 Ends */
      if ( ptr_fml_obuf == NULL )
      {
        fn_errlog( c_ServiceName, "S31385", TPMSG, c_errmsg  );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
    }

		/* if (c_apisrc_flg == 'A') *** If condition added in Ver 6.4 *** commented in ver 7.0
		*{ */
    i_rec_count = 0;/** ver 7.0 **/
		/*** Ver  3.4 comments begins ... Uncommented in Ver 6.4 starts ***/

		/*** Commented for Ver 8.3 ***

    EXEC SQL
       SELECT 1
       INTO   :i_rec_count
       FROM  dual
       WHERE exists
                  (
                   SELECT 1
                   FROM   fxb_fo_xchng_book
                   WHERE  fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc
                  );

    if ( ( SQLCODE != 0 ) && ( SQLCODE != NO_DATA_FOUND ) )
    {
      fn_errlog( c_ServiceName, "S31390", SQLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
			tpfree ( ( char * )ptr_fml_obuf);
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

      if ( i_rec_count != 1 )
      {
				EXEC SQL
            SELECT    nvl(to_char(FXB_ACK_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-'),
											nvl(to_char(FXB_RQST_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-')	*** Ver 6.4 **
            INTO      :c_ack_time,
											:c_rqst_time	*** Ver 6.4 **
            FROM      fxb_fo_xchng_book_hstry
            WHERE     fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                      fxb_mdfctn_cntr = ( SELECT  nvl(MAX(FXB_MDFCTN_CNTR),1)
                                          FROM    fxb_fo_xchng_book_hstry
                                          WHERE   fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                                                  fxb_plcd_stts = 'A'
                                        );
      }
      else
      {

        EXEC SQL
            SELECT    nvl(to_char(FXB_ACK_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-'),
											nvl(to_char(FXB_RQST_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-')	*** Ver 6.4 **
            INTO      :c_ack_time,
											:c_rqst_time	*** Ver 6.4 **
            FROM      fxb_fo_xchng_book
            WHERE     fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                      fxb_mdfctn_cntr = ( SELECT  nvl(MAX(FXB_MDFCTN_CNTR),1)
                                          FROM    fxb_fo_xchng_book
                                          WHERE   fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                                                  fxb_plcd_stts = 'A'
                                        );

      }

      if ( (SQLCODE != 0) && (SQLCODE != NO_DATA_FOUND) )
      {
        fn_errlog( c_ServiceName, "S31395", SQLMSG, c_errmsg );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
				tpfree ( ( char * )ptr_fml_obuf);
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, (char*)c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, ( char * )ptr_fml_ibuf, 0, 0 );
      }
			*   SETNULL( c_request_tm );   **** ver 1.6 *******

      if ( (SQLCODE == NO_DATA_FOUND) )
      {
        strcpy((char*)c_ack_time.arr,"*");
				strcpy((char*)c_rqst_time.arr,"*");	*** Ver 6.4 **
      }
      else
      {
        SETNULL( c_ack_time );
				SETNULL( c_rqst_time );
      } *** Ver 3.4 comment ends ... Uncommented in Ver 6.4 ends ***

			*** Ver 8.3 ***/

			/*** Added for Ver 8.3 ***/

			if(li_rec_cnt_status_date != 1)
			{
      	EXEC SQL
          	SELECT    nvl(to_char(FXB_ACK_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-'),
											nvl(to_char(FXB_RQST_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-')	
            INTO      :c_ack_time,
											:c_rqst_time	
            FROM      fxb_fo_xchng_book
            WHERE     fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                      fxb_mdfctn_cntr = ( SELECT  nvl(MAX(FXB_MDFCTN_CNTR),1)
                                          FROM    fxb_fo_xchng_book
                                          WHERE   fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                                                  fxb_plcd_stts = 'A'
                                        );

      	if ( (SQLCODE != 0) && (SQLCODE != NO_DATA_FOUND) )
      	{
        	fn_errlog( c_ServiceName, "S31400", SQLMSG, c_errmsg );
        	EXEC SQL CLOSE :sys_cursor;
        	EXEC SQL FREE :sys_cursor;
					tpfree ( ( char * )ptr_fml_obuf);
        	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, (char*)c_errmsg, 0 );
        	tpreturn(TPFAIL, ERR_BFR, ( char * )ptr_fml_ibuf, 0, 0 );
				}
				else if(SQLCODE == NO_DATA_FOUND)
				{
        	strcpy((char*)c_ack_time.arr,"*");
					strcpy((char*)c_rqst_time.arr,"*");	
				}
			}
			else if(li_rec_cnt_status_date == 1)
			{
      	EXEC SQL
          	SELECT    nvl(to_char(FXB_ACK_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-'),
											nvl(to_char(FXB_RQST_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-')	
            INTO      :c_ack_time,
											:c_rqst_time	
            FROM      fxb_fo_xchng_book
            WHERE     fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                      fxb_mdfctn_cntr = ( SELECT  nvl(MAX(FXB_MDFCTN_CNTR),1)
                                          FROM    fxb_fo_xchng_book
                                          WHERE   fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                                                  fxb_plcd_stts = 'A'
                                        );

      	if ( (SQLCODE != 0) && (SQLCODE != NO_DATA_FOUND) )
      	{
        	fn_errlog( c_ServiceName, "S31405", SQLMSG, c_errmsg );
        	EXEC SQL CLOSE :sys_cursor;
        	EXEC SQL FREE :sys_cursor;
					tpfree ( ( char * )ptr_fml_obuf);
        	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, (char*)c_errmsg, 0 );
        	tpreturn(TPFAIL, ERR_BFR, ( char * )ptr_fml_ibuf, 0, 0 );
				}
				else if(SQLCODE == NO_DATA_FOUND)
				{
					fn_userlog(c_ServiceName,"FXB Inside History check");

      		EXEC SQL
          	SELECT    nvl(to_char(FXB_ACK_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-'),
											nvl(to_char(FXB_RQST_TM, 'dd-Mon-yyyy hh24:mi:ss'),'-')	
            INTO      :c_ack_time,
											:c_rqst_time	
            FROM      fxb_fo_xchng_book_HSTRY
            WHERE     fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                      fxb_mdfctn_cntr = ( SELECT  nvl(MAX(FXB_MDFCTN_CNTR),1)
                                          FROM    fxb_fo_xchng_book
                                          WHERE   fxb_ordr_rfrnc = :ptr_st_orderbook->c_ordr_rfrnc AND
                                                  fxb_plcd_stts = 'A'
                                        );

      		if ( (SQLCODE != 0) && (SQLCODE != NO_DATA_FOUND) )
      		{
        		fn_errlog( c_ServiceName, "S31410", SQLMSG, c_errmsg );
        		EXEC SQL CLOSE :sys_cursor;
        		EXEC SQL FREE :sys_cursor;
						tpfree ( ( char * )ptr_fml_obuf);
        		Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, (char*)c_errmsg, 0 );
        		tpreturn(TPFAIL, ERR_BFR, ( char * )ptr_fml_ibuf, 0, 0 );
					}
					else if(SQLCODE == NO_DATA_FOUND)
					{
        		strcpy((char*)c_ack_time.arr,"*");
						strcpy((char*)c_rqst_time.arr,"*");
					}
				}
			}

			SETLEN(c_ack_time);
			SETLEN(c_rqst_time);
      SETNULL( c_ack_time );
			SETNULL( c_rqst_time );

			if( DEBUG_MSG_LVL_3 ) 
			{
				fn_userlog(c_ServiceName,"Value of c_ack_time :%s:",c_ack_time.arr);
				fn_userlog(c_ServiceName,"Value of c_rqst_time :%s:",c_rqst_time.arr);
			}

			/*** End for Ver 8.3 ***/
			
		/* commented in ver 7.0 } *** If condiftion added in Ver 6.4 ***/

			if( DEBUG_MSG_LVL_3 ) 
			{ /*  Ver 1.8 : Debug level Change  */
      	fn_userlog( c_ServiceName, "C_ORDER_RFRNC before packing is :%s",ptr_st_orderbook->c_ordr_rfrnc );
      	fn_userlog( c_ServiceName, "C_ACK_TIME before packing is :%s",c_ack_time.arr );
				fn_userlog( c_ServiceName, "C_RQST_TIME before packing is :%s",c_rqst_time.arr );
			}
			strcpy ( ptr_st_orderbook->c_ack_tm,   ( char * ) c_ack_time.arr ); 


		/*** Ver 6.4 starts ***/
		if (c_apisrc_flg != 'A') /*** Site call ***/
		{

			  EXEC SQL
				SELECT NVL(IAD_INDV_COMP_NAME,'*')
				INTO   :c_esp_nm
				FROM   IAD_IDIRECT_API_DTLS
				WHERE  IAD_ECO_SYS_PRTNR_CD = :c_esp_id
				AND		 ROWNUM = 1; /*** Ver 6.8 ***/

				if( (SQLCODE != 0) && (SQLCODE != NO_DATA_FOUND) )
				{
					fn_errlog( c_ServiceName, "S31415","Error in fetching ESP NAME",c_errmsg);
					Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_err_msg, 0 );
					tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
				}
			 if (SQLCODE == NO_DATA_FOUND)
			 {
					strcpy(c_esp_nm ,"*");
			 }
		  rtrim(c_esp_nm);
			
			if( DEBUG_MSG_LVL_5 )
			{
				fn_userlog(c_ServiceName,"Order Ref :%s: ESP_ID :%s: ESP_NM :%s:",ptr_st_orderbook->c_ordr_rfrnc,c_esp_id.arr,c_esp_nm);
			}
		}
	  /*** Ver 6.4 ends ***/

		/***Added by SANGEET to recover from NOSPACE ERROR **/
    if ( Fneeded32( 1, l_bufferlength ) > Funused32( ptr_fml_obuf ) )
    {
      i_counter++;

			/* Ver 1.9 starts  */
			
      /*ptr_fml_obuf = ( FBFR32 *)tprealloc( (char *)ptr_fml_obuf,
                       (i_counter * l_bufferlength * BUF_MULTIPLY) );*/

				ptr_fml_obuf = ( FBFR32 *)tprealloc( (char *)ptr_fml_obuf,
                       (Fsizeof32(ptr_fml_obuf) + (i_counter *l_bufferlength )));		
				/* Ver 1.9 Ends */

      if ( ptr_fml_obuf == NULL )
      {
        fn_errlog( c_ServiceName, "S31420", TPMSG, c_errmsg  );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
    }

	/****** Commented for Ver 4.2 ****
    i_returncode = Fvstof32( ptr_fml_obuf, (char *) ptr_st_orderbook,
                              FCONCAT, "vw_orderbook" );
	****** Commented for Ver 4.2 ****/
	
	/**** Added for Ver 4.2 *****/

    i_returncode = fn_pack_vartofml(c_ServiceName,
                                    c_errmsg,
                                    &ptr_fml_obuf,
                                    34,	/*** ver 6.9  from 32 to 33 ***/            /** Changed 50 to 49 in Ver 4.7 **/  /** Changed 49 to 50 in Ver 5.4 **/ /** Changed 50 to 51 in Ver 5.5 **/ /** changed from 51 to 30 in Ver 6.0 **/ /*** Changed from 30 to 32 in Ver 6.4 ***/
                                    /*** Commented in Ver 6.0
																		FFO_USR_ID, (char*)ptr_st_orderbook->c_user_id,
																		FFO_OPERATION_TYP, (char*)&ptr_st_orderbook->c_oprn_typ,
                                    ***/

																		FFO_EBA_MTCH_ACT_NO, (char*)ptr_st_orderbook->c_cln_mtch_accnt,
																		FFO_ORDR_RFRNC, (char*)ptr_st_orderbook->c_ordr_rfrnc,
																		FFO_PIPE_ID, (char*)ptr_st_orderbook->c_pipe_id,
																		FFO_XCHNG_CD, (char*)ptr_st_orderbook->c_xchng_cd,
																		FFO_PRDCT_TYP, (char*)&ptr_st_orderbook->c_prd_typ,
																		FFO_CTGRY_INDSTK, (char*)&ptr_st_orderbook->c_ctgry_indstk,
																		FFO_UNDRLYNG, (char*)ptr_st_orderbook->c_undrlyng,
																		FFO_EXER_TYP, (char*)&ptr_st_orderbook->c_exrc_typ,
																		FFO_OPT_TYP, (char*)&ptr_st_orderbook->c_opt_typ,
																		FFO_STRK_PRC, (char*)&ptr_st_orderbook->l_strike_prc,
																		FFO_ORDR_FLW, (char*)&ptr_st_orderbook->c_ordr_flw,
																		FFO_LMT_MKT_SL_FLG, (char*)&ptr_st_orderbook->c_slm_flg,
																		FFO_DSCLSD_QTY, (char*)&ptr_st_orderbook->l_dsclsd_qty,
																		FFO_ORD_TOT_QTY, (char*)&ptr_st_orderbook->l_ord_tot_qty,
																		FFO_LMT_RT, (char*)&ptr_st_orderbook->l_ord_lmt_rt,
																		FFO_STP_LSS_TGR, (char*)&ptr_st_orderbook->l_stp_lss_tgr,
																		FFO_ORD_TYP, (char*)&ptr_st_orderbook->c_ord_typ,
																		FFO_ORDR_STTS, (char*)&ptr_st_orderbook->c_ordr_stts,
																		FFO_EXEC_QTY, (char*)&ptr_st_orderbook->l_exctd_qty,
																		FFO_CANCL_QTY, (char*)&ptr_st_orderbook->l_can_qty,
																		FFO_EXPRD_QTY, (char*)&ptr_st_orderbook->l_exprd_qty,
																		/*FFO_SPRD_ORD_REF, (char*)ptr_st_orderbook->c_sprd_ord_rfrnc,                       Commented in Ver 4.7*/
                                    /*** Commented in Ver 6.0 ***
																		FFO_SETTLOR, (char*)ptr_st_orderbook->c_settlor,
																		FFO_MDFCTN_CNTR, (char*)&ptr_st_orderbook->l_mdfctn_cntr,
                                    ***/

																		FFO_ACK_NMBR, (char*)ptr_st_orderbook->c_xchng_ack,
																		FFO_SPL_FLG, (char*)&ptr_st_orderbook->c_spl_flg,
																		FFO_CHANNEL, (char*)ptr_st_orderbook->c_channel,

                                    /*** Commented in Ver 6.0 ***
																		FFO_BP_ID, (char*)ptr_st_orderbook->c_bp_id,
                                    ***/	
  
   																	FFO_ACK_TM, (char*)ptr_st_orderbook->c_ack_tm,
																	 
                                    /*** Commented in Ver 6.0 ***
                                  	FFO_SSSN_ID, (char*)&ptr_st_orderbook->l_session_id,
																		FFO_DPID, (char*)ptr_st_orderbook->c_dp_id,
																		FFO_CLNT_DPID, (char*)ptr_st_orderbook->c_dp_clnt_id,
																		FFO_BNK_ACT_NO, (char*)ptr_st_orderbook->c_bnk_accnt_nmbr,
																		FFO_CLNT_CTGRY, (char*)&ptr_st_orderbook->l_clnt_ctgry,
																		FFO_USR_FLG, (char*)&ptr_st_orderbook->l_usr_flg,
																		FFO_EBA_CNTRCT_ID, (char*)&ptr_st_orderbook->l_eba_cntrct_id,
                                    ***/

																		FFO_EXPRY_DT, (char*)ptr_st_orderbook->c_expry_dt,

                                    /*** Commented in Ver 6.0 ***
																		FFO_CA_LVL, (char*)&ptr_st_orderbook->l_ca_lvl,
                                    ***/
                             
																		FFO_ORD_VALID_DT, (char*)ptr_st_orderbook->c_valid_dt,
																		FFO_TRD_DT, (char*)ptr_st_orderbook->c_trd_dt,
																
                                    /*** Commented in Ver 6.0 ***
                                		FFO_EXEC_QTY_DAY, (char*)&ptr_st_orderbook->l_exctd_qty_day,
																		FFO_REQ_TYP, (char*)&ptr_st_orderbook->c_req_typ,
																		FFO_PREV_ACK_TM, (char*)ptr_st_orderbook->c_prev_ack_tm,
																		FFO_PRO_CLI_IND, (char*)&ptr_st_orderbook->c_pro_cli_ind,
																		FFO_ROUT_CRT, (char*)ptr_st_orderbook->c_rout_crt,
																		FFO_CTCL_ID, (char*)&ptr_st_orderbook->c_ctcl_id,
																		FFO_CSE_ID, (char*)&ptr_st_orderbook->l_cse_id,
																		FFO_MKT_TYP, (char*)&ptr_st_orderbook->c_mrkt_typ,
                                    ***/
 
																		FFO_NXT_TRD_DT, (char*)c_nxt_trade_dt.arr,             /** Ver 5.4 **/	
																		FFO_PRC_INDCTR, (char*)&c_prcimpv_flg,                 /** Ver 5.5 **/		
																		FFO_RQST_TM,(char*)c_rqst_time.arr,								  	/*** Ver 6.4 ***/
																		FFO_QSPACE_NAME,(char*)c_esp_nm,											/*** Ver 6.4 ***/
																		FFO_BK_UBK_FLG,(char*)&c_1clk_flg,							/*** ver 6.9 ***/
                                    FFO_FUT_CONV_FLG,(char*)&c_src_flg);             /*** Ver 7.7 ***/
																		
    if ( i_returncode == -1 )
    {
      if( Ferror32 == FNOSPACE )
      {
        i_counter++;


				ptr_fml_obuf = ( FBFR32 *)tprealloc( (char *)ptr_fml_obuf,
                       (Fsizeof32(ptr_fml_obuf) + (i_counter *l_bufferlength )));
					/* Ver 1.9 Ends */

        if ( ptr_fml_obuf == NULL )
        {
          fn_errlog( c_ServiceName, "S31425", TPMSG, c_errmsg  );
          EXEC SQL CLOSE :sys_cursor;
          EXEC SQL FREE :sys_cursor;
					free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
          Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
          tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
        }
				
				/******** Commented for Ver 4.2 *******
				i_returncode = Fvstof32( ptr_fml_obuf, (char *) ptr_st_orderbook,
                                 FCONCAT, "vw_orderbook" );
				********** Ver 4.2 ***/

		/**** Added for Ver 4.2 ***/
    i_returncode = fn_pack_vartofml(c_ServiceName,
                                    c_errmsg,
                                    &ptr_fml_obuf,
                                    34,/**ver 6.9 from 32 to 33 **/     /** Changed 50 to 49 in Ver 4.7 **/  /** Changed 49 to 50 in Ver 5.4 **/     /** Changed 50 to 51 in Ver 5.5 **/ /** changed from 51 to 30 in Ver 6.0 **/ /*** Changed from 30 to 32 in Ver 6.4 ***/
                                    /***  Commented in Ver 6.0 ***
																		FFO_USR_ID, (char*)ptr_st_orderbook->c_user_id,
																		FFO_OPERATION_TYP, (char*)&ptr_st_orderbook->c_oprn_typ,
                                    ***/

																		FFO_EBA_MTCH_ACT_NO, (char*)ptr_st_orderbook->c_cln_mtch_accnt,
																		FFO_ORDR_RFRNC, (char*)ptr_st_orderbook->c_ordr_rfrnc,
																		FFO_PIPE_ID, (char*)ptr_st_orderbook->c_pipe_id,
																		FFO_XCHNG_CD, (char*)ptr_st_orderbook->c_xchng_cd,
																		FFO_PRDCT_TYP, (char*)&ptr_st_orderbook->c_prd_typ,
																		FFO_CTGRY_INDSTK, (char*)&ptr_st_orderbook->c_ctgry_indstk,
																		FFO_UNDRLYNG, (char*)ptr_st_orderbook->c_undrlyng,
																		FFO_EXER_TYP, (char*)&ptr_st_orderbook->c_exrc_typ,
																		FFO_OPT_TYP, (char*)&ptr_st_orderbook->c_opt_typ,
																		FFO_STRK_PRC, (char*)&ptr_st_orderbook->l_strike_prc,
																		FFO_ORDR_FLW, (char*)&ptr_st_orderbook->c_ordr_flw,
																		FFO_LMT_MKT_SL_FLG, (char*)&ptr_st_orderbook->c_slm_flg,
																		FFO_DSCLSD_QTY, (char*)&ptr_st_orderbook->l_dsclsd_qty,
																		FFO_ORD_TOT_QTY, (char*)&ptr_st_orderbook->l_ord_tot_qty,
																		FFO_LMT_RT, (char*)&ptr_st_orderbook->l_ord_lmt_rt,
																		FFO_STP_LSS_TGR, (char*)&ptr_st_orderbook->l_stp_lss_tgr,
																		FFO_ORD_TYP, (char*)&ptr_st_orderbook->c_ord_typ,
																		FFO_ORDR_STTS, (char*)&ptr_st_orderbook->c_ordr_stts,
																		FFO_EXEC_QTY, (char*)&ptr_st_orderbook->l_exctd_qty,
																		FFO_CANCL_QTY, (char*)&ptr_st_orderbook->l_can_qty,
																		FFO_EXPRD_QTY, (char*)&ptr_st_orderbook->l_exprd_qty,
																	/*	FFO_SPRD_ORD_REF, (char*)ptr_st_orderbook->c_sprd_ord_rfrnc,                                   Commented in Ver 4.7*/
                                    /***  Commented in Ver 6.0 ***
																		FFO_SETTLOR, (char*)ptr_st_orderbook->c_settlor,
																		FFO_MDFCTN_CNTR, (char*)&ptr_st_orderbook->l_mdfctn_cntr,
                                    ***/
 
																		FFO_ACK_NMBR, (char*)ptr_st_orderbook->c_xchng_ack,
																		FFO_SPL_FLG, (char*)&ptr_st_orderbook->c_spl_flg,
																		FFO_CHANNEL, (char*)ptr_st_orderbook->c_channel,

                                    /***  Commented in Ver 6.0 ***
																		FFO_BP_ID, (char*)ptr_st_orderbook->c_bp_id,
                                    ***/
 
																		FFO_ACK_TM, (char*)ptr_st_orderbook->c_ack_tm,

                                    /***  Commented in Ver 6.0 ***
																		FFO_SSSN_ID, (char*)&ptr_st_orderbook->l_session_id,
																		FFO_DPID, (char*)ptr_st_orderbook->c_dp_id,
																		FFO_CLNT_DPID, (char*)ptr_st_orderbook->c_dp_clnt_id,
																		FFO_BNK_ACT_NO, (char*)ptr_st_orderbook->c_bnk_accnt_nmbr,
																		FFO_CLNT_CTGRY, (char*)&ptr_st_orderbook->l_clnt_ctgry,
																		FFO_USR_FLG, (char*)&ptr_st_orderbook->l_usr_flg,
																		FFO_EBA_CNTRCT_ID, (char*)&ptr_st_orderbook->l_eba_cntrct_id,
                                    ***/

																		FFO_EXPRY_DT, (char*)ptr_st_orderbook->c_expry_dt,
                                   
                                    /***  Commented in Ver 6.0 ***
																		FFO_CA_LVL, (char*)&ptr_st_orderbook->l_ca_lvl,
                                    ***/

																		FFO_ORD_VALID_DT, (char*)ptr_st_orderbook->c_valid_dt,
																		FFO_TRD_DT, (char*)ptr_st_orderbook->c_trd_dt,
                                   
                                    /***  Commented in Ver 6.0 *** 
 																		FFO_EXEC_QTY_DAY, (char*)&ptr_st_orderbook->l_exctd_qty_day,
																		FFO_REQ_TYP, (char*)&ptr_st_orderbook->c_req_typ,
																		FFO_PREV_ACK_TM, (char*)ptr_st_orderbook->c_prev_ack_tm,
																		FFO_PRO_CLI_IND, (char*)&ptr_st_orderbook->c_pro_cli_ind,
																		FFO_ROUT_CRT, (char*)ptr_st_orderbook->c_rout_crt,
																		FFO_CTCL_ID, (char*)&ptr_st_orderbook->c_ctcl_id,
																		FFO_CSE_ID, (char*)&ptr_st_orderbook->l_cse_id,
																		FFO_MKT_TYP, (char*)&ptr_st_orderbook->c_mrkt_typ,
                                    ***/

																		FFO_NXT_TRD_DT, (char*)c_nxt_trade_dt.arr,          /** Ver 5.4 **/
																		FFO_PRC_INDCTR, (char*)&c_prcimpv_flg,              /** Ver 5.5 **/
																		FFO_RQST_TM,(char*)c_rqst_time.arr ,								/*** Ver 6.4 ***/
																		FFO_QSPACE_NAME,(char*)c_esp_nm,										/*** Ver 6.4 ***/
																		FFO_BK_UBK_FLG,(char*)&c_1clk_flg,									/*** ver 6.9 ***/
                                    FFO_FUT_CONV_FLG,(char*)&c_src_flg);             /*** Ver 7.7 ***/


			/******* Ver 4.2 ***/

        if ( i_returncode == -1 )
        {
          fn_errlog( c_ServiceName, "S31430", FMLMSG, c_errmsg  );
          EXEC SQL CLOSE :sys_cursor;
          EXEC SQL FREE :sys_cursor;
          tpfree ( ( char * ) ptr_fml_obuf );
					free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
          Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
          tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
        }
				/*** Ver 6.3 starts ***/
				if( ptr_st_orderbook->c_prd_typ == 'F' )
				{
					if ( Fadd32 ( ptr_fml_obuf,FFO_SPRD_ORD_REF ,( char *)c_tag_ordr_rfrnce,0) == -1)
					{
						fn_errlog( c_ServiceName, "S31435",FMLMSG,c_errmsg);
						EXEC SQL CLOSE :sys_cursor;
						EXEC SQL FREE :sys_cursor;
						tpfree ( ( char * ) ptr_fml_obuf );
						free((char *)ptr_st_orderbook);
						strcpy(c_errmsg,"Problem in adding Tagged order order type");
						Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
						tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
					}
				}
				/*** Ver 6.3 Ends ***/
      }
      else
      {
        fn_errlog( c_ServiceName, "S31440", FMLMSG, c_errmsg  );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
        tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
    }
		/*** Ver 6.3 Starts ***/
		if( ptr_st_orderbook->c_prd_typ == 'F' )
		{
			if ( Fadd32 ( ptr_fml_obuf,FFO_SPRD_ORD_REF ,( char *)c_tag_ordr_rfrnce,0) == -1)
			{
				fn_errlog( c_ServiceName, "S31445",FMLMSG,c_errmsg);
				EXEC SQL CLOSE :sys_cursor;
				EXEC SQL FREE :sys_cursor;
				tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);
				strcpy(c_errmsg,"Problem in adding Tagged order order type");
				Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
				tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}
		}
		/*** Ver 6.3 Ends ***/
	
    if ( Fadd32 ( ptr_fml_obuf, FFO_XCHNG_RMRKS,
                                (char *)c_remarks, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31450", FMLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
	
		c_mod_can_flg = 'N';
     c_cancel_can_flg='N';   /**** Ver 4.7 ****/
     c_sqoff_at_mkt  = 'N';  /***  Ver 5.0 ***/

    /********* Ver 6.0  ******************************************************************************************

      If condition added to skip Action Link logic for below cases ,

      1]  Trading Screen : When request comes through Trading Screen we can skip below logic as we use trading
          screen only for display purpose.
      2]  History Records : For history records we never display links,so we can skip below action link logic.
      3]  Intraday Records : We can skip below logic for records having order status other than Requested,Ordered,
          and Part Executed as we display action link against these three order status only.

    **************************************************************************************************************/


   if( st_usr_prfl.l_session_id != 0 && ( ( ptr_st_orderbook->c_ordr_stts == REQUESTED ) ||
                                          ( ptr_st_orderbook->c_ordr_stts == ORDERED ) ||
                                          ( ptr_st_orderbook->c_ordr_stts == PARTIALLY_EXECUTED ) ) )
   {

		/** Added for Temporary order book  ***/

		if ( strncmp ( ptr_st_orderbook->c_ordr_rfrnc,"TP",2) == 0 )
		{
			if ( ptr_st_orderbook->c_ordr_stts == CANCELLED )
			{
				c_mod_can_flg = 'N';
        c_cancel_can_flg='N';   /*** Ver 4.7 ***/
			}
			else
			{
				c_mod_can_flg = 'Y';
        c_cancel_can_flg='Y';  /*** Ver 4.7 ***/
			}
		}
		else
		{
			if ( ( ptr_st_orderbook->c_ordr_stts == REQUESTED ) || 
					 ( ptr_st_orderbook->c_ordr_stts == ORDERED ) ||
					 ( ptr_st_orderbook->c_ordr_stts == PARTIALLY_EXECUTED ) )
			{
				c_mod_can_flg = 'Y';

			}

			d_trail_amt = 0.0;            /** Ver 5.5 **/
      d_trl_upd_cond_val = 0.0;     /** Ver 5.5 **/
      d_incrmnt_prc = 0.0;          /** Ver 5.5 **/

			if ( ( ptr_st_orderbook->c_ordr_stts == ORDERED ) ||
					 ( ptr_st_orderbook->c_ordr_stts == PARTIALLY_EXECUTED ) )
	    {
        if( DEBUG_MSG_LVL_4 ) /** Ver 3.8, Added in debug level **/
        {
         fn_userlog(c_ServiceName,"ptr_st_orderbook->c_xchng_cd :%s:",ptr_st_orderbook->c_xchng_cd);
         fn_userlog(c_ServiceName,"ptr_st_orderbook->c_ordr_rfrnc :%s:",ptr_st_orderbook->c_ordr_rfrnc);
         fn_userlog(c_ServiceName,"ptr_st_orderbook->l_mdfctn_cntr :%ld:",ptr_st_orderbook->l_mdfctn_cntr);
        }
	       EXEC SQL
							SELECT fxb_rqst_typ,
										 fxb_plcd_stts,
										 NVL(fxb_trail_amt,0),            /*** Ver 5.5 ***/
                     NVL(fxb_trl_upd_cond_val,0),     /*** Ver 5.5 ***/
                     NVL(fxb_incrmnt_prc,0)           /*** Ver 5.5 ***/
							INTO 	 :c_rqst_typ,
										 :c_plcd_stts,
										 :d_trail_amt,              /*** Ver 5.5 ***/
                     :d_trl_upd_cond_val,       /*** Ver 5.5 ***/
                     :d_incrmnt_prc             /*** Ver 5.5 ***/				
							FROM fxb_fo_xchng_book
							WHERE	fxb_xchng_cd 		= :ptr_st_orderbook->c_xchng_cd
							AND		fxb_ordr_rfrnc 	=	:ptr_st_orderbook->c_ordr_rfrnc
							AND		fxb_mdfctn_cntr = :ptr_st_orderbook->l_mdfctn_cntr;
	      if ( SQLCODE != 0 )
	  		{
						fn_errlog( c_ServiceName, "S31455", SQLMSG, c_errmsg  );
	      		EXEC SQL CLOSE :sys_cursor;
	      		EXEC SQL FREE :sys_cursor;
	      		tpfree ( ( char * ) ptr_fml_obuf );
						free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
	      		Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
	      		tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
	  		}
	      if (( c_rqst_typ == CANCELLED ) && ( c_plcd_stts != REJECT ))
	      {
						c_mod_can_flg = 'N';
             c_cancel_can_flg='N';         /*** Ver 4.7 ***/
/***
						#ifdef DEBUG
							fn_userlog(c_ServiceName,"Inside c_mod_can_flg is N II");
						#endif					***/
	      }
	    }
	    if ( (ptr_st_orderbook->c_spl_flg == SYSTEM_SQUAREOFF    ) ||
					 (ptr_st_orderbook->c_spl_flg == L2_ORDER            ) ||
					 (ptr_st_orderbook->c_spl_flg == L3_ORDER            ) ||
           (ptr_st_orderbook->c_spl_flg == IMTM_SYS_SQUAREOFF ) ||                  /*** Ver 3.8 ***/
           (ptr_st_orderbook->c_spl_flg == LMTNEG_SYS_SQUAREOFF ) ||                  /*** Ver 3.8 ***/
	         (ptr_st_orderbook->c_ord_typ == IMMEDIATE_OR_CANCEL )  
	       )
	    {
						c_mod_can_flg = 'N';
            c_cancel_can_flg='N';         /*** Ver 4.7 ***/
	    }

      /*** Ver 4.6 Starts Here ****/
      if( (ptr_st_orderbook->c_spl_flg == SYSTEM_SQUAREOFF    ) &&
          ( ptr_st_orderbook->c_ord_typ == 'V' ) &&
          ( ( ptr_st_orderbook->c_ordr_stts == REQUESTED ) ||
           ( ptr_st_orderbook->c_ordr_stts == ORDERED ) ||
           ( ptr_st_orderbook->c_ordr_stts == PARTIALLY_EXECUTED )
          )
        )
      {
         c_mod_can_flg = 'Y';
      }
      /*** Ver 4.6 Ends Here ****/
			
      /*** Ver 6.3 Starts Here ****/
      if( (ptr_st_orderbook->c_spl_flg == 'O') &&
          (( ptr_st_orderbook->c_ordr_stts == ORDERED ) ||
           ( ptr_st_orderbook->c_ordr_stts == PARTIALLY_EXECUTED )))
      {
         c_mod_can_flg = 'Y';
      }
      /*** Ver 6.3 Ends Here ****/
 
		}

    /*** Commented in Ver 6.0 as this part logic is taken below to avoid extra datatbase hit to Order Book ***  
 
		*** Ver 3.1 starts here ***
		if (( ptr_st_orderbook->c_prd_typ == SLTP_FUTUREPLUS || ptr_st_orderbook->c_prd_typ == OPTIONPLUS ) && c_mod_can_flg == 'Y')  *** Ver 3.6 Condition added for optionplus handling *** 
		{
			if ( c_fc_flg == FRESH )
			{
					c_mod_can_flg = 'N';
          c_sqoff_at_mkt= 'N';  *** Ver 5.0 ***
			}
			else if ( c_fc_flg == COVER )
      {
        EXEC SQL
          SELECT FOD_ORDR_STTS
          INTO   :c_frsh_ord_stts
          FROM   FOD_FO_ORDR_DTLS
          WHERE  FOD_ORDR_RFRNC = ( SELECT FOD_SLTP_ORDR_RFRNC FROM FOD_FO_ORDR_DTLS WHERE FOD_ORDR_RFRNC = :ptr_st_orderbook->c_ordr_rfrnc);

        if ( SQLCODE != 0 )
        {
          fn_errlog( c_ServiceName, "S31460", SQLMSG, c_errmsg  );
          EXEC SQL CLOSE :sys_cursor;
          EXEC SQL FREE :sys_cursor;
          tpfree ( ( char * ) ptr_fml_obuf );
					free((char *)ptr_st_orderbook);		** Ver 4.8 **
          Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
          tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
        }

        if ( c_frsh_ord_stts == EXECUTED && (ptr_st_orderbook->c_ordr_stts == ORDERED || ptr_st_orderbook->c_ordr_stts == PARTIALLY_EXECUTED ) )
        {
          c_mod_can_flg = 'Y';
          c_sqoff_at_mkt= 'Y';  *** Ver 5.0 ***
        }
				else
				{
					c_mod_can_flg = 'N';
          c_sqoff_at_mkt= 'N';  *** Ver 5.0 ***
				}
      }
      
      if(DEBUG_MSG_LVL_0)
     {
      fn_userlog(c_ServiceName,"Square Off at Market Flag Is :%c:",c_sqoff_at_mkt);
      fn_userlog(c_ServiceName,"Modify Flag Is :%c:",c_mod_can_flg);
     }

		}
		*** Ver 3.1 ends here ***
  
    ********************** Ver 6.0 Comment Ends ************************/
 
    /*** Ver 4.7 Starts ***/
 
    /*** Commented in Ver 5.0 ****    

     if ((ptr_st_orderbook->c_prd_typ == 'U' || ptr_st_orderbook->c_prd_typ == 'I') && c_chk_new_site_flg== 'N' )   ** c_prd_typ == 'I' check added in Ver 4.9 **
         
    *******/
    if(ptr_st_orderbook->c_prd_typ == 'U' || ptr_st_orderbook->c_prd_typ == 'I')   /*** Ver 5.0 ***/
    {
     /*** fn_userlog(c_ServiceName,"test condition 1"); Commented in Ver 5.2 ***/
    /* fn_userlog(c_ServiceName,"c_tag_ordr_rfrnce %s",c_tag_ordr_rfrnce);
			fn_userlog(c_ServiceName,"c_cln_mtch_accnt %s",ptr_st_orderbook->c_cln_mtch_accnt);*/
      EXEC SQL
      SELECT FOD_LMT_MRKT_SL_FLG,
             FOD_LMT_RT,
             FOD_STP_LSS_TGR,
             FOD_ORDR_STTS,
             FOD_EXEC_QTY,
             FOD_FC_FLAG,
             FOD_CNCL_QTY,
             FOD_EXPRD_QTY,
             FOD_ORDR_TOT_QTY
      INTO   :c_tag_ord_typ,
             :l_tag_ord_lmt_rt,
             :l_tag_sltp_tgr,
             :c_tag_ord_stts,
             :l_tag_exe_qty,
             :c_tag_frsh_cvr_flg,
             :l_tag_can_qty,
             :l_tag_exprd_qty,
             :l_tag_ordr_tot_qty
      FROM   FOD_FO_ORDR_DTLS
      WHERE  FOD_ORDR_RFRNC=:c_tag_ordr_rfrnce
      AND    FOD_CLM_MTCH_ACCNT= :ptr_st_orderbook->c_cln_mtch_accnt
     /*  AND    FOD_PRDCT_TYP='U';  commented in Ver 4.9*/
			AND    FOD_PRDCT_TYP IN ('U','I');  /** Ver 4.9 **/
   
     /*    fn_userlog(c_ServiceName,":c_tag_ord_typ:%c",c_tag_ord_typ);
      fn_userlog(c_ServiceName,":l_tag_ord_lmt_rt: %ld",l_tag_ord_lmt_rt);
      fn_userlog(c_ServiceName,":l_tag_sltp_tgr: %ld",l_tag_sltp_tgr);
      fn_userlog(c_ServiceName,":c_tag_ord_stts: %c",c_tag_ord_stts);
      fn_userlog(c_ServiceName,":l_tag_exe_qty: %ld",l_tag_exe_qty);
      fn_userlog(c_ServiceName,": c_tag_frsh_cvr_flg: %c",c_tag_frsh_cvr_flg);*/
     if ( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND)
     {
      fn_errlog( c_ServiceName, "S31465", SQLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }

 /*    fn_userlog(c_ServiceName," Tag Orderc total qty:%ld",l_tag_ordr_tot_qty);
     fn_userlog(c_ServiceName,"Tag Executed qty :%ld",l_tag_exe_qty);
     fn_userlog(c_ServiceName,"Tag Cancel Qty  : %ld",l_tag_can_qty);
     fn_userlog(c_ServiceName,"Tag exprd qty   : %ld",l_tag_exprd_qty);*/

     l_tag_open_qty=l_tag_ordr_tot_qty-(l_tag_exe_qty+l_tag_can_qty+l_tag_exprd_qty);

     if ( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/
     {
   	 	fn_userlog(c_ServiceName,"Tag Unexcuted qty: %ld",l_tag_open_qty);
     }
      
      c_mod_can_flg ='N';

      /***  Ver 5.0 Starts  ***/

      if( c_chk_new_site_flg != 'N' && c_opr_typ == ORDER_REF_IP )
      {

       if (DEBUG_MSG_LVL_3) /** Changes debug from 0 to 3 in Ver 7.6 **/
       {
        fn_userlog(c_ServiceName ," Fresh Cover Flag :%c:",c_fc_flg);
       }

       if( ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'O' )
       {
        c_can_srv_call = 'P';
        c_mod_srv_call = 'P';
       }
       else if( ptr_st_orderbook->c_ordr_stts == 'O' && ( c_tag_ord_stts == 'J' || c_tag_ord_stts == 'C' ))
       {
        c_can_srv_call  = 'C';
       }

       if ( c_tag_ord_stts == 'O' && ( ptr_st_orderbook->c_ordr_stts == 'J' || ptr_st_orderbook->c_ordr_stts == 'C'))
       {
        c_can_srv_call  = 'C';
       }
       if(( c_fc_flg == 'F' && ptr_st_orderbook->c_ordr_stts == 'E' && (c_tag_ord_stts == 'O' || c_tag_ord_stts == 'P')) ||
          ( c_fc_flg == 'C' && (ptr_st_orderbook->c_ordr_stts == 'O' || ptr_st_orderbook->c_ordr_stts == 'P') &&
            c_tag_ord_stts == 'E'))
       {
        c_mod_srv_call  = 'M';
       }
       else if((c_fc_flg == 'F' && ptr_st_orderbook->c_ordr_stts == 'P' && c_tag_ord_stts == 'O') ||
               (c_fc_flg == 'C' && ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'P'))
       {
        c_mod_srv_call  = 'P';
       }
      }

      if (DEBUG_MSG_LVL_3) /** Changes debug from 0 to 3 in Ver 7.6 **/
      {
       fn_userlog(c_ServiceName," Call modify service flag Is :%c:",c_mod_srv_call);
       fn_userlog(c_ServiceName," Call cancel service flag Is :%c:",c_can_srv_call);
      }

     /*** Ver 5.0 Ends  ***/

     if(( ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'O' && c_fc_flg != 'T')||		/*** Ver 7.1 added c_fc_flg != 'T' ***/   
         (ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'E' && c_fc_flg=='C' )||
         (ptr_st_orderbook->c_ordr_stts == 'P' && c_tag_ord_stts == 'E' && c_fc_flg=='C') ||
         (ptr_st_orderbook->c_ordr_stts == 'P' && c_tag_ord_stts == 'O' && c_fc_flg=='F') ||
         (ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'P' && c_fc_flg=='C') ||
         (ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'E' && c_fc_flg=='T'))			 /*** Added In Ver 7.1 ***/ 
      {
         c_mod_can_flg = 'Y';
       }

      /*** Above logic of setting SquareOff at Market flag brought here in Ver 6.0  ***/

      if(( ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'E' && c_fc_flg=='C' ) ||
         ( ptr_st_orderbook->c_ordr_stts == 'P' && c_tag_ord_stts == 'E' && c_fc_flg=='C' ))
      {
        c_sqoff_at_mkt = 'Y';
      }
      else
      {
        c_sqoff_at_mkt = 'N';
      }

      if ( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/
      {
      	fn_userlog(c_ServiceName,"Modfy flag :%c",c_mod_can_flg);
        fn_userlog(c_ServiceName,"Order Status %c",ptr_st_orderbook->c_ordr_stts);
        fn_userlog(c_ServiceName,"Tagged Order Status %c",c_tag_ord_stts);
        fn_userlog(c_ServiceName,"SquareOff at Market Flag :%c:", c_sqoff_at_mkt); /*** Ver 6.0 ***/
      }

       if(((  ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'O')||
       (  ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'J'  )||
      (   ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'C' ) ||
        (   ptr_st_orderbook->c_ordr_stts == 'J' && c_tag_ord_stts == 'O' ) ||
          (   ptr_st_orderbook->c_ordr_stts == 'C' && c_tag_ord_stts == 'O')) &&
           (ptr_st_orderbook->c_ordr_stts !='C' ) && ( ptr_st_orderbook->c_ordr_stts !='J'))
     {
       /*** fn_userlog(c_ServiceName,"Cancel Flag 6:%c",c_cancel_can_flg); Commented in Ver 5.2 ***/
       c_cancel_can_flg='Y';
       /*** fn_userlog(c_ServiceName,"Cancel Flag 7:%c",c_cancel_can_flg); Commented in Ver 5.2 ***/
     }
		
			 /*** Ver 7.1  start***/

      if (c_fc_flg == 'T')
      {
        if(ptr_st_orderbook->c_ordr_stts == 'O' && c_tag_ord_stts == 'E')
        {
           c_cancel_can_flg = 'Y';
        }
        else
        {
            c_cancel_can_flg = 'N';
        }
      }

      /*** Ver 7.1 Ends ***/
		
     if ( DEBUG_MSG_LVL_2 ) /*** Ver 5.2 ***/
     {
     	 fn_userlog(c_ServiceName,"Cancel Flag -----------------------------%c",c_cancel_can_flg);
     	 fn_userlog(c_ServiceName,"c_tag_ordr_rfrnce  :%s",c_tag_ordr_rfrnce);
     	 fn_userlog(c_ServiceName,"c_tag_ord_typ  :%c",c_tag_ord_typ);
     	 fn_userlog(c_ServiceName,"l_tag_ord_lmt_rt  :%ld",l_tag_ord_lmt_rt);
     	 fn_userlog(c_ServiceName,"l_tag_sltp_tgr  :%ld",l_tag_sltp_tgr);
     	 fn_userlog(c_ServiceName,"c_tag_ord_stts  :%c",c_tag_ord_stts);
     	 fn_userlog(c_ServiceName,"l_tag_exe_qty  :%ld",l_tag_exe_qty);
       fn_userlog(c_ServiceName,"c_tag_frsh_cvr_flg  :%c",c_tag_frsh_cvr_flg);
     }   

      /*** Commented in Ver 5.6 and taken below ***

      if ( Fadd32 ( ptr_fml_obuf,FFO_SPRD_ORD_REF ,( char *)c_tag_ordr_rfrnce,0) == -1)
      {
        fn_errlog( c_ServiceName, "S31470",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding Tagged order order type");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
     
      if ( Fadd32 ( ptr_fml_obuf,FFO_CLSR_TYP  ,( char *)&c_tag_ord_typ, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31475",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding Tagged order order type");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }

     if ( Fadd32 ( ptr_fml_obuf,FFO_CURR_RT  ,( char *)&l_tag_ord_lmt_rt, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31480",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding Tagged order limit rate");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }
      if ( Fadd32 ( ptr_fml_obuf,FFO_CVR_BRKG  ,( char *)&l_tag_sltp_tgr, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31485",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding tag order sltp");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }

     if ( Fadd32 ( ptr_fml_obuf,FFO_EXER_INIT  ,( char *)&c_tag_ord_stts, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31490",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding tag order ord status");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }
     if ( Fadd32 ( ptr_fml_obuf,FFO_IEXCTD_QTY  ,( char *)&l_tag_exe_qty, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31495",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding tag order exexuted quantity");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }
     if ( Fadd32 ( ptr_fml_obuf,FFO_IS_FLG  ,( char *)&c_fc_flg, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31500",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding tag order fresh cover flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }
    if ( Fadd32 ( ptr_fml_obuf,FFO_SALE_MRGN ,( char *)&l_tag_open_qty,0) ==-1)
     {
        fn_errlog( c_ServiceName, "S31505",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		** Ver 4.8 **
      strcpy(c_errmsg,"Problem in adding tag order fresh cover flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }

     *** Ver 5.6 Comment Ends ***/

    }

   } /*** Ver 6.0 if condition for cnt user and order status R,O and P ends  ***/
 
   /*** Ver 5.6 Starts ***/

   if(ptr_st_orderbook->c_prd_typ == 'U' || ptr_st_orderbook->c_prd_typ == 'I' || st_cntrct.c_prd_typ == ALL )
   {

    if(DEBUG_MSG_LVL_3) /** Changes debug from 0 to 3 in Ver 7.6 **/
    {
     fn_userlog(c_ServiceName,"Inside ALL condition for adding FMLs.");
    }

		if (ptr_st_orderbook->c_prd_typ != 'F') /*** if condition added in ver 6.7 ***/
		{
    if ( Fadd32 ( ptr_fml_obuf,FFO_SPRD_ORD_REF ,( char *)c_tag_ordr_rfrnce,0) == -1)
    {
      fn_errlog( c_ServiceName, "S31510",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding Tagged order order type");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
		}
    if ( Fadd32 ( ptr_fml_obuf,FFO_CLSR_TYP  ,( char *)&c_tag_ord_typ, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31515",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding Tagged order order type");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf,FFO_CURR_RT  ,( char *)&l_tag_ord_lmt_rt, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31520",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding Tagged order limit rate");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf,FFO_CVR_BRKG  ,( char *)&l_tag_sltp_tgr, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31525",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding tag order sltp");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf,FFO_EXER_INIT  ,( char *)&c_tag_ord_stts, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31530",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding tag order ord status");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf,FFO_IEXCTD_QTY  ,( char *)&l_tag_exe_qty, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31535",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding tag order exexuted quantity");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf,FFO_IS_FLG  ,( char *)&c_fc_flg, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31540",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding tag order fresh cover flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf,FFO_SALE_MRGN ,( char *)&l_tag_open_qty,0) ==-1)
    {
      fn_errlog( c_ServiceName, "S31545",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding tag order fresh cover flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
   }

   /*** Ver 5.6 Ends ***/

    if(strcmp(ptr_st_orderbook->c_channel,"SYS")==0 && (ptr_st_orderbook->c_prd_typ == 'U' || ptr_st_orderbook->c_prd_typ == 'I' ))/** c_prd_typ == 'I' Check added in ver 4.9 **/
    { 
			  c_cancel_can_flg='N';
 				c_mod_can_flg='N';				
    }
   
    if ( Fadd32 ( ptr_fml_obuf,FFO_MTM_FLG  ,( char *)&c_cancel_can_flg, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31550",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding cancel link flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }

   /*** Ver 4.7 Ends ***/
		
		  /*** Ver 7.1 starts ***/

    c_prft_pend = 'N';
    MEMSET(c_prft_penordrref);
    l_prft_lmt_rt = 0;

    if (c_fc_flg == 'C' )
    {
       EXEC SQL
       SELECT
              'Y',
              FOD_ORDR_RFRNC,
              FOD_LMT_RT
       INTO :c_prft_pend,
            :c_prft_penordrref,
            :l_prft_lmt_rt
       FROM FOD_FO_ORDR_DTLS
       WHERE FOD_FC_FLAG = 'T'
       AND DECODE(FOD_FC_FLAG, 'F', FOD_ORDR_RFRNC, FOD_SLTP_ORDR_RFRNC) = :c_tag_ordr_rfrnce
       AND FOD_ORDR_STTS in ( 'O','R','Q','P');

      if( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND )
      {
        fn_errlog( c_ServiceName, "S31555", SQLMSG, c_errmsg  );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
        tpfree ( ( char * ) ptr_fml_obuf );
        free((char *)ptr_st_orderbook);
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
     }

     if ( Fadd32 ( ptr_fml_obuf,FFO_TMPLT,( char *)&l_prft_lmt_rt, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31560",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding prft pend flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }

     if ( Fadd32 ( ptr_fml_obuf,FFO_EXRC_ORDR_RFRNC,( char *)c_prft_penordrref, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31565",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding prft pend flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }

     if ( Fadd32 ( ptr_fml_obuf,FFO_INDX_INDCTR,( char *)&c_prft_pend, 0 ) == -1 )
     {
      fn_errlog( c_ServiceName, "S31570",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding prft pend flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
     }
    /*** Ver 7.1ends ***/

		 /*** Ver 5.5 Starts here ***/

    if ( Fadd32 ( ptr_fml_obuf, FFO_BAL_AMT,( char *)&d_trail_amt, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31575",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding Trail Amount");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf, FFO_BASE_ORD_VAL,( char *)&d_trl_upd_cond_val, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31580",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding Trail Update Condition");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf, FFO_EFF_CLS_PRC,( char *)&d_incrmnt_prc, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31585",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding Incremental Price");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf, FFO_BNK_TRN_TYP,( char *)&c_sltp_trail_flag, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31590",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      free((char *)ptr_st_orderbook);
      strcpy(c_errmsg,"Problem in adding Trail Flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    /*** Ver 5.5 Ends here ***/	

   /*** Ver 5.0 Starts ***/

    if ( Fadd32 ( ptr_fml_obuf, FFO_EBA_STTS,(char *)&c_sqoff_at_mkt,0) == -1)   
    {
      fn_errlog( c_ServiceName, "S31595", FMLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf, FML_PLG_FLG,(char *)&c_mod_srv_call,0) == -1)   
    {
      fn_errlog( c_ServiceName, "S31600", FMLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    if ( Fadd32 ( ptr_fml_obuf, FFO_PLG_REV_TYP,(char *)&c_can_srv_call,0) == -1)  
    {
      fn_errlog( c_ServiceName, "S31605", FMLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
    
    /*** Ver 5.0 Ends ***/
  
    if ( Fadd32 ( ptr_fml_obuf, FFO_MOD_CAN_FLG, 
																(char *)&c_mod_can_flg, 0 ) == -1 )
  	{
			fn_errlog( c_ServiceName, "S31610", FMLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  	}

    /******* DLRevamp ver 1.6 starts  *******/


    strcpy( c_dbc_channel, "");
    if( ptr_st_orderbook->c_bp_id[0] == BPID && ptr_st_orderbook->c_user_id[0] == BPID  )			/***	Ver	2.3	***/
    {
      /**strcpy( c_dbc_channel, strcat( strcpy( c_dbc_channel, ptr_st_orderbook->c_channel ), " DBC" ));*Ver 2.3*commented in 3.0**/

			/**** Ver 3.0 Changes for ERS starts**/

      i_catagory_types =0 ;

      EXEC SQL
        SELECT  nvl(ID_CATEGORY_TYPES,0)
        INTO  :i_catagory_types
        FROM BP_BRKR_MSTR , BPA_INWARD_DETAILS
        WHERE BBM_GRP_ID  = ID_SUB_BROKER_CODE
        AND   BBM_BP_ID   = :ptr_st_orderbook->c_bp_id;

      if( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND )
      {
      	fn_errlog( c_ServiceName, "S31615", SQLMSG, c_errmsg  );
      	EXEC SQL CLOSE :sys_cursor;
      	EXEC SQL FREE :sys_cursor;
      	tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      	Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      	tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      if(i_catagory_types != 3)   /** 3 is for ERS */
      {
				strcpy( c_dbc_channel, strcat( strcpy( c_dbc_channel, ptr_st_orderbook->c_channel ), " DBC" ));
      }
      else
      {
				strcpy( c_dbc_channel, strcat( strcpy( c_dbc_channel, ptr_st_orderbook->c_channel ), " ERS" ));
      }

      /**** Ver 3.0 Changes for ERS ends**/

      if ( Fadd32 ( ptr_fml_obuf, FFO_SERIES, (char *)c_dbc_channel, 0 ) == -1)
      {
        fn_errlog( c_ServiceName, "S31620", FMLMSG, c_errmsg  );
			  EXEC SQL CLOSE :sys_cursor;
			  EXEC SQL FREE :sys_cursor;
			  tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
        strcpy(c_errmsg,"Problem in adding DBC channel");
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
    }
    else
    {
      if ( Fadd32 ( ptr_fml_obuf, FFO_SERIES, (char *) ptr_st_orderbook->c_channel, 0 ) == -1)
      {
        fn_errlog( c_ServiceName, "S31625", FMLMSG, c_errmsg  );
			  EXEC SQL CLOSE :sys_cursor;
			  EXEC SQL FREE :sys_cursor;
			  tpfree ( ( char * ) ptr_fml_obuf );
				free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
        strcpy(c_errmsg,"Problem in adding DBC channel");
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
    }

		if( ptr_st_orderbook->c_ordr_stts != REJECT )
		{
      l_open_qty = ptr_st_orderbook->l_ord_tot_qty - ( ptr_st_orderbook->l_exctd_qty   +
                                                       ptr_st_orderbook->l_can_qty     +
                                                       ptr_st_orderbook->l_exprd_qty     );
		}

		if( DEBUG_MSG_LVL_3 ) 
		{ /*  Ver 1.8 : Debug level Change  */
    	fn_userlog(c_ServiceName,"c_bp_id[0] is :%c:", ptr_st_orderbook->c_bp_id[0]);
    	fn_userlog(c_ServiceName,"c_channel is :%s:", ptr_st_orderbook->c_channel);
    	fn_userlog(c_ServiceName,"c_dbc_channel is :%s:", c_dbc_channel);
    	fn_userlog(c_ServiceName,"l_open_qty is :%ld:", l_open_qty);
		}


    if ( Fadd32 ( ptr_fml_obuf, FFO_C_OPNPSTN_QTY,( char *)&l_open_qty, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31630",FMLMSG,c_errmsg);
			EXEC SQL CLOSE :sys_cursor;
			EXEC SQL FREE :sys_cursor;
			tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding Open Quantity");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
    /****  DLRevamp ver 1.6 ends ****/

		/***	Ver	2.5	Starts	***/

	
/**** Ver 3.4 Moved up before assigning WEB to c_channel 
		EXEC SQL
			SELECT	NVL(FTQ_LST_TRD_PRC,0)
			INTO		:l_ltp_prc
			FROM		FTQ_FO_TRD_QT
			WHERE		FTQ_XCHNG_CD	= :ptr_st_orderbook->c_xchng_cd															***  Ver 2.6 ***
			AND			FTQ_PRDCT_TYP	=	decode(:ptr_st_orderbook->c_prd_typ,'P','F',:ptr_st_orderbook->c_prd_typ)
			AND			FTQ_UNDRLYNG	=	:ptr_st_orderbook->c_undrlyng
			AND			FTQ_EXPRY_DT	=	:c_exp_date
			AND			FTQ_EXER_TYP	=	:ptr_st_orderbook->c_exrc_typ
			AND			FTQ_OPT_TYP		=	:ptr_st_orderbook->c_opt_typ
			AND			FTQ_STRK_PRC	=	:ptr_st_orderbook->l_strike_prc;
    
		if ( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND)
    {
    	fn_errlog( c_ServiceName, "S31635", SQLMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  	}

		if( DEBUG_MSG_LVL_3 ) 
		{
			fn_userlog(c_ServiceName,"l_ltp_prc:%ld:",l_ltp_prc);
		}

		if ( Fadd32 ( ptr_fml_obuf,FFO_LST_TRD_PRC ,( char *)&l_ltp_prc, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31640",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
      strcpy(c_errmsg,"Problem in adding Open Quantity");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    } 	Ver 3.4 *****/

	/***	Ver	2.5	Ends	***/
		
		/*** Ver 3.1 starts here ***/
		if ( Fadd32 ( ptr_fml_obuf,FFO_ORD_AMT_BLKD ,( char *)&d_mrgn_blk, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31645",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding Margin+loss amount blocked");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

		/*** Ver 3.1 Ends here ***/

		/*** Ver 3.2 starts here ***/
		if ( Fadd32 ( ptr_fml_obuf,FFO_SOURCE_FLG ,( char *)&c_spn_flg, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31650",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding span flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
		/*** Ver 3.2 Ends here ***/

		/*** Ver 4.1 Starts ***/

	  l_exctd_rt = 0;
	
		if( d_trd_val != 0 || ptr_st_orderbook->l_exctd_qty != 0)
		{	
			l_exctd_rt  = (long)(d_trd_val/ptr_st_orderbook->l_exctd_qty);
		}

    if ( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/
    {
			fn_userlog(c_ServiceName,"Brokerage :%ld:",l_brkg_val);
			fn_userlog(c_ServiceName,"Trade Value :%lf:",d_trd_val);
			fn_userlog(c_ServiceName,"Executed Rate :%ld:",l_exctd_rt);
	  }

		if ( Fadd32 ( ptr_fml_obuf,FFO_BRKRG_VL ,( char *)&l_brkg_val, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31655",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding span flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

		if ( Fadd32 ( ptr_fml_obuf,FFO_OPNPSTN_VAL,( char *)&d_trd_val, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31660",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding span flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
		
	
		if ( Fadd32 ( ptr_fml_obuf,FFO_EXCTD_RT,( char *)&l_exctd_rt, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31665",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding span flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

		if ( Fadd32 ( ptr_fml_obuf,FFO_AGREE_NO,( char *)c_cntrct_num, 0 ) == -1 )
    {
      fn_errlog( c_ServiceName, "S31670",FMLMSG,c_errmsg);
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
      strcpy(c_errmsg,"Problem in adding span flag");
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
		/*** Ver 4.1 Ends 	***/

			MEMSET(c_stop_vtc_flg);		/** Ver 6.1 **/
			c_stop_vtc_flg = 'N';			/** Ver 6.1 **/

		/*** Version 6.1 Start **/

		 if (ptr_st_orderbook->c_ord_typ == 'V' && ptr_st_orderbook->c_ordr_stts == REJECT && strcmp(ptr_st_orderbook->c_channel,"SYS")==0)
		{

			EXEC SQL
			SELECT COUNT(1) 
			 INTO  :li_rec_main_exists
			 FROM  FXB_FO_XCHNG_BOOK
			 WHERE FXB_ORDR_RFRNC = :ptr_st_orderbook->c_ordr_rfrnc;

      if(DEBUG_MSG_LVL_3) /* Added debug level Ver 7.6 */
			{
				fn_userlog(c_ServiceName,"li_rec_main_exists :%ld:",li_rec_main_exists);
			}

			if ( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND)
			{
			 fn_errlog( c_ServiceName, "S31675", SQLMSG, c_errmsg  );
			 EXEC SQL CLOSE :sys_cursor;
			 EXEC SQL FREE :sys_cursor;
			 tpfree ( ( char * ) ptr_fml_obuf );
			 Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
			 tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
			}

			if (li_rec_main_exists == 0)
			{
				c_stop_vtc_flg = 'N';
			}
			else
			{
        rec_price_rjct = 0;

				EXEC SQL
					SELECT 1
					INTO :rec_price_rjct
					FROM  FXB_FO_XCHNG_BOOK
					WHERE FXB_ORDR_RFRNC = :ptr_st_orderbook->c_ordr_rfrnc
					AND   (FXB_XCHNG_RMRKS like '%Your order is outside the price range%'
					OR     FXB_XCHNG_RMRKS like '%Your order is outside the specified price range%'
					OR     FXB_XCHNG_RMRKS like '%Price entered by you  is beyond the price range permitted by exchange%'
					OR     FXB_XCHNG_RMRKS like '%The order price is out of the days price range%')
					AND   ROWNUM < 2;
 				
				if(DEBUG_MSG_LVL_3) /* Added debug level Ver 7.6 */
				{ 
        	fn_userlog(c_ServiceName,"rec_price_rjct :%d",rec_price_rjct);
       	}

				if ( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND)
				{
					fn_errlog( c_ServiceName, "S31680", SQLMSG, c_errmsg  );
					EXEC SQL CLOSE :sys_cursor;
					EXEC SQL FREE :sys_cursor;
					tpfree ( ( char * ) ptr_fml_obuf );
					Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
					tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
				}
				if (SQLCODE == NO_DATA_FOUND)
				{
					c_stop_vtc_flg = 'N';
				}

				if (c_fc_flg != 'Y' && rec_price_rjct == 1)
				{
					c_stop_vtc_flg = 'Y';
				}
				else
				{
					c_stop_vtc_flg = 'N';
				}
			}

		}
		
		if(DEBUG_MSG_LVL_3) /* Added debug level Ver 7.6 */
		{
    	fn_userlog(c_ServiceName,"c_stop_vtc_flg :%c:",c_stop_vtc_flg);
		}

		if ( Fadd32 ( ptr_fml_obuf,FFO_DR_CR_FLG,( char *)&c_stop_vtc_flg, 0 ) == -1 )
		{
			fn_errlog( c_ServiceName, "S31685",FMLMSG,c_errmsg);
			EXEC SQL CLOSE :sys_cursor;
			EXEC SQL FREE :sys_cursor;
			tpfree ( ( char * ) ptr_fml_obuf );
			free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
			strcpy(c_errmsg,"Problem in adding span flag");
			Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
			tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
		}
		/*** Version 6.1 Ends **/

    /** Ver 8.4 **/
    if( c_last_leg == 'Y' )
    {
      break;
    }
 
	}	/**End of For loop **/

	i_counter --;


	/***	Ver	2.5	Starts	***/
  
	/*** Ver 4.3 moved up to select exchange next trade date ***
 
	MEMSET(c_ordbk_seq);

  EXEC SQL
    SELECT TO_CHAR(EXG_NXT_TRD_DT,'YYYYMMDD')||LPAD(TO_CHAR(DECODE((LAST_NUMBER - 1),MAX_VALUE,0,(LAST_NUMBER - 1))),8,'0')
    INTO  :c_ordbk_seq
    FROM  USER_SEQUENCES,EXG_XCHNG_MSTR
    WHERE SEQUENCE_NAME = 'DFO_DL_FO_ORDBK_SEQ'
		AND		EXG_XCHNG_CD	=	'NFO';

  SETNULL(c_ordbk_seq);

	Ver 4.3 Comment Ends	***/


  if(DEBUG_MSG_LVL_3)
  {
    fn_userlog(c_ServiceName,"Order Book Sequence number is :%s:",c_ordbk_seq.arr);
  }

  if ( Fadd32(ptr_fml_obuf,FFO_REF_NO,(char *)c_ordbk_seq.arr,0) == -1 )
  {
		fn_errlog( c_ServiceName, "S31690", FMLMSG, c_errmsg  );
		free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
		tpfree ( ( char * ) ptr_fml_obuf );	/** Ver 4.8 **/
 		Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
 		tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }
 
/**** ver 8.4 nikhil ****/

  if(DEBUG_MSG_LVL_3)
  {
    fn_userlog(c_ServiceName,"Pages number count is :%ld: total_pages:%ld:",l_page_rec_cnt,l_tot_pages);
  }

  if ( Fadd32(ptr_fml_obuf,FFO_REC_NO,(char *)&l_tot_pages,0) == -1 )
  {
    fn_errlog( c_ServiceName, "S31695", FMLMSG, c_errmsg  );
    free((char *)ptr_st_orderbook);   /** Ver 4.8 **/
    tpfree ( ( char * ) ptr_fml_obuf ); /** Ver 4.8 **/
    Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
    tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
  }


 /**** ver 8.4 nikhil ****/


	/***	Ver	2.5	Ends	***/

	EXEC SQL CLOSE :sys_cursor;
  EXEC SQL FREE :sys_cursor;
 
 }
 else  /*** VTC Order Log *** Ver 4.6 Starts Here ***/
 {
    ptr_fml_obuf = NULL;  /** Ver 5.3 **/

    SETLEN( c_ordr_ref );
   
   if ( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/
   {
 	   fn_userlog(c_ServiceName, "VTC Order Log" );
  	 fn_userlog(c_ServiceName, "c_ordr_ref = :%s:", c_ordr_ref.arr);
   }
 
   i_loop_cnt=1;

   EXEC SQL ALLOCATE :sys_cursor;

   EXEC SQL  EXECUTE
          BEGIN
            OPEN  :sys_cursor FOR
     SELECT
            FOD_CLM_MTCH_ACCNT,
            FOD_ORDR_RFRNC,
            FOD_PIPE_ID,
            FOD_XCHNG_CD,
            FOD_PRDCT_TYP,
            FOD_INDSTK,
            FOD_UNDRLYNG,
            to_date(FOD_EXPRY_DT,'DD-Mon-YYYY'),
            FOD_EXER_TYP,
            FOD_OPT_TYP,
            FOD_STRK_PRC,
            FOD_ORDR_FLW,
            FOD_LMT_MRKT_SL_FLG,
            FOD_DSCLSD_QTY,
            FOD_ORDR_TOT_QTY,
            FOD_LMT_RT,
            FOD_STP_LSS_TGR,
            FOD_ORDR_TYPE,
            to_date(FOD_ORDR_VALID_DT,'DD-Mon-YYYY'),
            FOD_TRD_DT,
            FOD_ORDR_STTS,
            FOD_EXEC_QTY,
            FOD_CNCL_QTY,
            FOD_EXPRD_QTY,
            nvl(FOD_SPRD_ORDR_REF,' '),
            FOD_CHANNEL ,
            NVL( fod_ack_nmbr, ' ' ),
					 NVL(FOD_1CLICK_FLG,'N'),             /*** ver 6.9 ***/
            NVL(FOD_SOURCE_FLG, '*'),                            /*** Ver 7.7 ***/
						FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
       FROM FOD_FO_ORDR_DTLS,FXB_FO_XCHNG_BOOK /** FXB_FO_XCHNG_BOOK added in Ver 8.8 **/
      WHERE FOD_CLM_MTCH_ACCNT =:c_mtch_accnt_no
        AND FOD_SLTP_ORDR_RFRNC = ( SELECT FOD_SLTP_ORDR_RFRNC
                                      FROM FOD_FO_ORDR_DTLS
                                     WHERE FOD_ORDR_RFRNC =:c_ordr_ref
                                       AND FOD_CLM_MTCH_ACCNT=:c_mtch_accnt_no
                                  )
        AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
			  AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
     UNION ALL
          SELECT
            FOD_CLM_MTCH_ACCNT,
            FOD_ORDR_RFRNC,
            FOD_PIPE_ID,
            FOD_XCHNG_CD,
            FOD_PRDCT_TYP,
            FOD_INDSTK,
            FOD_UNDRLYNG,
            to_date(FOD_EXPRY_DT,'DD-Mon-YYYY'),
            FOD_EXER_TYP,
            FOD_OPT_TYP,
            FOD_STRK_PRC,
            FOD_ORDR_FLW,
            FOD_LMT_MRKT_SL_FLG,
            FOD_DSCLSD_QTY,
            FOD_ORDR_TOT_QTY,
            FOD_LMT_RT,
            FOD_STP_LSS_TGR,
            FOD_ORDR_TYPE,
            to_date(FOD_ORDR_VALID_DT,'DD-Mon-YYYY'),
            FOD_TRD_DT,
            FOD_ORDR_STTS,
            FOD_EXEC_QTY,
            FOD_CNCL_QTY,
            FOD_EXPRD_QTY,
            nvl(FOD_SPRD_ORDR_REF,' '),
            FOD_CHANNEL,
            NVL( fod_ack_nmbr, ' ' ),
					 NVL(FOD_1CLICK_FLG,'N'),             /*** ver 6.9 ***/
            NVL(FOD_SOURCE_FLG, '*'),                           /*** Ver 7.7 ***/
						FXB_RQST_TM      /** Added in Ver 8.8 by Vishal **/
       FROM FOD_FO_ORDR_DTLS_HSTRY,FXB_FO_XCHNG_BOOK_HSTRY /** FXB_FO_XCHNG_BOOK_HSTRY added in Ver 8.8 **/
      WHERE FOD_CLM_MTCH_ACCNT =:c_mtch_accnt_no
        AND FOD_SLTP_ORDR_RFRNC = ( SELECT FOD_SLTP_ORDR_RFRNC
                                      FROM FOD_FO_ORDR_DTLS_HSTRY
                                     WHERE FOD_ORDR_RFRNC =:c_ordr_ref
                                       AND FOD_CLM_MTCH_ACCNT=:c_mtch_accnt_no
                                  )
				AND     FXB_ORDR_RFRNC    = FOD_ORDR_RFRNC /** Added in Ver 8.8 by Vishal **/
			  AND     FXB_MDFCTN_CNTR   = FOD_MDFCTN_CNTR /** Added in Ver 8.8 by Vishal **/
       /**  ORDER BY 1,2 DESC; **/ /** Commnented in Ver 8.8 **/
				ORDER BY FOD_CLM_MTCH_ACCNT,FXB_RQST_TM DESC,FOD_ORDR_RFRNC DESC; /** Added in Ver 8.8 **/
          END;
        END-EXEC;

     if ( SQLCODE != 0 )
    {
      fn_errlog( c_ServiceName, "S31700", SQLMSG, c_errmsg  );
      EXEC SQL FREE :sys_cursor;
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
   
    /**** Commented in ver 5.3 *** 
    ptr_fml_obuf = (FBFR32 *)tpalloc( "FML32", NULL, MIN_FML_BUF_LEN * BUF_MULTIPLY * 2 );

    if ( ptr_fml_obuf == NULL )
    {
      fn_errlog( c_ServiceName, "S31705", TPMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }
    *******Ver 5.3 Ends here   ****/
 
    ptr_st_orderbook = malloc(sizeof(struct vw_orderbook));

    if ( ptr_st_orderbook == NULL )
    {
      fn_errlog( c_ServiceName, "S31710", TPMSG, c_errmsg  );
      EXEC SQL CLOSE :sys_cursor;
      EXEC SQL FREE :sys_cursor;
      /*** tpfree ( ( char * )ptr_fml_obuf); ** Ver 5.3 **/
      Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
      tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
    }

    l_bufferlength =  sizeof( struct vw_orderbook )
                   +  1024;

    memset ( ptr_st_orderbook, 0, sizeof ( struct vw_orderbook ) );

    strcpy ( ptr_st_orderbook->c_user_id, st_usr_prfl.c_user_id );
    ptr_st_orderbook->c_oprn_typ = c_opr_typ;
    strcpy ( ptr_st_orderbook->c_cln_mtch_accnt, c_mtch_accnt_no );

    i_counter = 1 ;

    for ( ; ; )
    {

     EXEC SQL FETCH :sys_cursor
              INTO :ptr_st_orderbook->c_cln_mtch_accnt,
                   :ptr_st_orderbook->c_ordr_rfrnc,
                   :ptr_st_orderbook->c_pipe_id,
                   :ptr_st_orderbook->c_xchng_cd,
                   :ptr_st_orderbook->c_prd_typ,
                   :ptr_st_orderbook->c_ctgry_indstk,
                   :ptr_st_orderbook->c_undrlyng,
                   :c_exp_date,
                   :ptr_st_orderbook->c_exrc_typ,
                   :ptr_st_orderbook->c_opt_typ,
                   :ptr_st_orderbook->l_strike_prc,
                   :ptr_st_orderbook->c_ordr_flw,
                   :ptr_st_orderbook->c_slm_flg,
                   :ptr_st_orderbook->l_dsclsd_qty,
                   :ptr_st_orderbook->l_ord_tot_qty,
                   :ptr_st_orderbook->l_ord_lmt_rt,
                   :ptr_st_orderbook->l_stp_lss_tgr,
                   :ptr_st_orderbook->c_ord_typ,
                   :c_valid_date,
                   :c_trd_date,
                   :ptr_st_orderbook->c_ordr_stts,
                   :ptr_st_orderbook->l_exctd_qty,
                   :ptr_st_orderbook->l_can_qty,
                   :ptr_st_orderbook->l_exprd_qty,
                   :ptr_st_orderbook->c_sprd_ord_rfrnc,
                   :ptr_st_orderbook->c_channel,
                   :ptr_st_orderbook->c_xchng_ack,
									 :c_1clk_flg,			/*** ver 6.9 ***/
                   :c_src_flg;                     /*** Ver 7.7 ***/

    if ( SQLCODE != 0 )
    {
      if ( SQLCODE == NO_DATA_FOUND )
      {
        break;
      }
      else
      {
        fn_errlog( c_ServiceName, "S31715", SQLMSG, c_errmsg  );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
        tpfree ( ( char * ) ptr_fml_obuf );
        free((char*)ptr_st_orderbook);  /** Ver 5.3 **/
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }
    }
    
    if ( DEBUG_MSG_LVL_1 ) /*** Ver 5.2 ***/
    {
			fn_userlog(c_ServiceName,"1clk_flag :%c",c_1clk_flg);			/*** ver 6.9  ***/
    	fn_userlog(c_ServiceName,"SPAN FLAG :%c:",c_spn_flg);                                             /*** Ver 3.2 ***/
    	fn_userlog(c_ServiceName,"ptr_st_orderbook->c_ordr_rfrnc :%s:",ptr_st_orderbook->c_ordr_rfrnc);   /*** Ver 3.2 ***/
    }
   
    strcpy ( ptr_st_orderbook->c_expry_dt, ( char * ) c_exp_date.arr );
    strcpy ( ptr_st_orderbook->c_valid_dt, ( char * ) c_valid_date.arr );
    strcpy ( ptr_st_orderbook->c_trd_dt,   ( char * ) c_trd_date.arr );
    
    c_vtc_ord_stts='N';
    i_vtc_cnt=0;

    if( i_loop_cnt == 1 && ( ptr_st_orderbook->c_ordr_stts=='X' || ptr_st_orderbook->c_ordr_stts=='B') )
    {
      i_loop_cnt =0;
      i_vtc_cnt =0;

      EXEC SQL
        SELECT count(1)
          INTO :i_vtc_cnt
          FROM exg_xchng_mstr
         WHERE to_date(exg_nxt_trd_dt,'dd-Mon-yyyy') > to_date(:c_valid_date,'dd-Mon-yyyy')
          AND  EXG_XCHNG_CD =:ptr_st_orderbook->c_xchng_cd;
      if ( SQLCODE != 0 && SQLCODE != NO_DATA_FOUND )
      {
        fn_errlog( c_ServiceName, "S31720", SQLMSG, c_errmsg  );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
        tpfree ( ( char * ) ptr_fml_obuf );
        free((char*)ptr_st_orderbook);  /** Ver 5.3 **/
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      }

      if(  i_vtc_cnt > 0 )
      {
        if ( DEBUG_MSG_LVL_3 ) /*** Ver 5.2 ***/  /*** ver 5.3 , debug level changed from 1 to 0 ***/ /** Changes debug from 0 to 3 in Ver 7.6 **/
        {
        	fn_userlog(c_ServiceName," VTC Closed Order :%s:",ptr_st_orderbook->c_ordr_rfrnc);
        }

         c_vtc_ord_stts='C';
      }
    }

    if ( ptr_st_orderbook->c_ordr_stts=='J' )
    {
      c_vtc_ord_stts='C';
    }

    /*** Ver 5.9 Starts ***/

    if( ptr_st_orderbook->c_ordr_stts != REJECT )
    {
      l_open_qty = ptr_st_orderbook->l_ord_tot_qty -
                 ( ptr_st_orderbook->l_exctd_qty + ptr_st_orderbook->l_can_qty + ptr_st_orderbook->l_exprd_qty );
    }

    if ( DEBUG_MSG_LVL_3 ) /** Changes debug from 0 to 3 in Ver 7.6 **/
    fn_userlog(c_ServiceName,"Open Quantity Is :%ld:",l_open_qty);

    /*** Ver 5.9 Ends ***/

    i_returncode = fn_pack_vartofml(c_ServiceName,
                                    c_errmsg,
                                    &ptr_fml_obuf,
                                    35,    /** ver 6.9 changed from 33 to34 **/ /** Changed 31 to 32 in Ver 5.4 **//** changed to 33 in Ver 5.9 **/
                                    FFO_OPERATION_TYP, (char*)&ptr_st_orderbook->c_oprn_typ,
                                    FFO_EBA_MTCH_ACT_NO, (char*)ptr_st_orderbook->c_cln_mtch_accnt,
                                    FFO_ORDR_RFRNC, (char*)ptr_st_orderbook->c_ordr_rfrnc,
                                    FFO_PIPE_ID, (char*)ptr_st_orderbook->c_pipe_id,
                                    FFO_XCHNG_CD, (char*)ptr_st_orderbook->c_xchng_cd,
                                    FFO_PRDCT_TYP, (char*)&ptr_st_orderbook->c_prd_typ,
                                    FFO_CTGRY_INDSTK, (char*)&ptr_st_orderbook->c_ctgry_indstk,
                                    FFO_UNDRLYNG, (char*)ptr_st_orderbook->c_undrlyng,
                                    FFO_EXER_TYP, (char*)&ptr_st_orderbook->c_exrc_typ,
                                    FFO_OPT_TYP, (char*)&ptr_st_orderbook->c_opt_typ,
                                    FFO_STRK_PRC, (char*)&ptr_st_orderbook->l_strike_prc,
                                    FFO_ORDR_FLW, (char*)&ptr_st_orderbook->c_ordr_flw,
                                    FFO_LMT_MKT_SL_FLG, (char*)&ptr_st_orderbook->c_slm_flg,
                                    FFO_DSCLSD_QTY, (char*)&ptr_st_orderbook->l_dsclsd_qty,
                                    FFO_ORD_TOT_QTY, (char*)&ptr_st_orderbook->l_ord_tot_qty,
                                    FFO_LMT_RT, (char*)&ptr_st_orderbook->l_ord_lmt_rt,
                                    FFO_STP_LSS_TGR, (char*)&ptr_st_orderbook->l_stp_lss_tgr,
                                    FFO_ORD_TYP, (char*)&ptr_st_orderbook->c_ord_typ,
                                    FFO_ORDR_STTS, (char*)&ptr_st_orderbook->c_ordr_stts,
                                    FFO_EXEC_QTY, (char*)&ptr_st_orderbook->l_exctd_qty,
                                    FFO_CANCL_QTY, (char*)&ptr_st_orderbook->l_can_qty,
                                    FFO_EXPRD_QTY, (char*)&ptr_st_orderbook->l_exprd_qty,
                                    FFO_SPRD_ORD_REF, (char*)ptr_st_orderbook->c_sprd_ord_rfrnc,
                                    FFO_CHANNEL, (char*)ptr_st_orderbook->c_channel,
                                    FFO_EXPRY_DT, (char*)ptr_st_orderbook->c_expry_dt,
                                    FFO_ORD_VALID_DT, (char*)ptr_st_orderbook->c_valid_dt,
                                    FFO_TRD_DT, (char*)ptr_st_orderbook->c_trd_dt,
                                    FFO_EXEC_QTY_DAY, (char*)&ptr_st_orderbook->l_exctd_qty_day,
                                    FFO_REQ_TYP, (char*)&ptr_st_orderbook->c_req_typ,
                                    FFO_ACK_NMBR, (char*)ptr_st_orderbook->c_xchng_ack,
                                    FFO_SOURCE_FLG,(char*)&c_vtc_ord_stts,
																		FFO_NXT_TRD_DT, (char*)c_nxt_trade_dt.arr,             /** Ver 5.4 **/
                                    FFO_C_OPNPSTN_QTY, (char*)&l_open_qty,                /** Ver 5.9 **/
																		FFO_BK_UBK_FLG,(char*)&c_1clk_flg,											/*** ver 6.9 ***/
                                    FFO_FUT_CONV_FLG,(char*)&c_src_flg             /*** Ver 7.7 ***/
                                   );

       if ( i_returncode == -100 )
     {
      /**** Commented in Ver 5.3 *******************
      if( Ferror32 == FNOSPACE )
      {
        i_counter++;


        ptr_fml_obuf = ( FBFR32 *)tprealloc( (char *)ptr_fml_obuf,
                       (Fsizeof32(ptr_fml_obuf) + (i_counter *l_bufferlength )));

        if ( ptr_fml_obuf == NULL )
        {
          fn_errlog( c_ServiceName, "S31725", TPMSG, c_errmsg  );
          EXEC SQL CLOSE :sys_cursor;
          EXEC SQL FREE :sys_cursor;
          Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
          tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
        }

        i_returncode = fn_pack_vartofml(c_ServiceName,
                                    c_errmsg,
                                    &ptr_fml_obuf,
                                    33,
                                    FFO_OPERATION_TYP, (char*)&ptr_st_orderbook->c_oprn_typ,
                                    FFO_EBA_MTCH_ACT_NO, (char*)ptr_st_orderbook->c_cln_mtch_accnt,
                                    FFO_ORDR_RFRNC, (char*)ptr_st_orderbook->c_ordr_rfrnc,
                                    FFO_PIPE_ID, (char*)ptr_st_orderbook->c_pipe_id,
                                    FFO_XCHNG_CD, (char*)ptr_st_orderbook->c_xchng_cd,
                                    FFO_PRDCT_TYP, (char*)&ptr_st_orderbook->c_prd_typ,
                                    FFO_CTGRY_INDSTK, (char*)&ptr_st_orderbook->c_ctgry_indstk,
                                    FFO_UNDRLYNG, (char*)ptr_st_orderbook->c_undrlyng,
                                    FFO_EXER_TYP, (char*)&ptr_st_orderbook->c_exrc_typ,
                                    FFO_OPT_TYP, (char*)&ptr_st_orderbook->c_opt_typ,
                                    FFO_STRK_PRC, (char*)&ptr_st_orderbook->l_strike_prc,
                                    FFO_ORDR_FLW, (char*)&ptr_st_orderbook->c_ordr_flw,
                                    FFO_LMT_MKT_SL_FLG, (char*)&ptr_st_orderbook->c_slm_flg,
                                    FFO_DSCLSD_QTY, (char*)&ptr_st_orderbook->l_dsclsd_qty,
                                    FFO_ORD_TOT_QTY, (char*)&ptr_st_orderbook->l_ord_tot_qty,
                                    FFO_LMT_RT, (char*)&ptr_st_orderbook->l_ord_lmt_rt,
                                    FFO_STP_LSS_TGR, (char*)&ptr_st_orderbook->l_stp_lss_tgr,
                                    FFO_ORD_TYP, (char*)&ptr_st_orderbook->c_ord_typ,
                                    FFO_ORDR_STTS, (char*)&ptr_st_orderbook->c_ordr_stts,
                                    FFO_EXEC_QTY, (char*)&ptr_st_orderbook->l_exctd_qty,
                                    FFO_CANCL_QTY, (char*)&ptr_st_orderbook->l_can_qty,
                                    FFO_EXPRD_QTY, (char*)&ptr_st_orderbook->l_exprd_qty,
                                    FFO_SPRD_ORD_REF, (char*)ptr_st_orderbook->c_sprd_ord_rfrnc,
                                    FFO_CHANNEL, (char*)ptr_st_orderbook->c_channel,
                                    FFO_EXPRY_DT, (char*)ptr_st_orderbook->c_expry_dt,
                                    FFO_ORD_VALID_DT, (char*)ptr_st_orderbook->c_valid_dt,
                                    FFO_TRD_DT, (char*)ptr_st_orderbook->c_trd_dt,
                                    FFO_EXEC_QTY_DAY, (char*)&ptr_st_orderbook->l_exctd_qty_day,
                                    FFO_REQ_TYP, (char*)&ptr_st_orderbook->c_req_typ,
                                    FFO_ACK_NMBR, (char*)ptr_st_orderbook->c_xchng_ack,
                                    FFO_SOURCE_FLG,(char*)&c_vtc_ord_stts,
                                   );	
         if ( i_returncode == -1)
        {
          fn_errlog( c_ServiceName, "S31730", FMLMSG, c_errmsg  );
          EXEC SQL CLOSE :sys_cursor;
          EXEC SQL FREE :sys_cursor;
          tpfree ( ( char * ) ptr_fml_obuf );
          Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
          tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
        }
      }
      else
      { ****** Ver 5.3 ***
        fn_errlog( c_ServiceName, "S31735", FMLMSG, c_errmsg  );
        EXEC SQL CLOSE :sys_cursor;
        EXEC SQL FREE :sys_cursor;
        tpfree ( ( char * ) ptr_fml_obuf );
        free((char *)ptr_st_orderbook);
        Fadd32( ptr_fml_ibuf, FFO_ERR_MSG, c_errmsg, 0 );
        tpreturn(TPFAIL, ERR_BFR, (char *)ptr_fml_ibuf, 0, 0 );
      ****} *** ver 5.3 ***/
    }
   }

   EXEC SQL CLOSE :sys_cursor;
   EXEC SQL FREE :sys_cursor;
  
   

 } /*** VTC Order Log *** Ver 4.6 Ends here ***/


	if( DEBUG_MSG_LVL_3 ) 
	{          /*  Ver 1.8 : Debug level Change  */
		fn_userlog(c_ServiceName, "END OF SFO_ORDR_BOOKP for :%s:",ptr_st_orderbook->c_cln_mtch_accnt);
	}

	free((char *)ptr_st_orderbook);		/** Ver 4.8 **/
	tpreturn( TPSUCCESS, 0, (char *)ptr_fml_obuf, 0 , 0 );
}

