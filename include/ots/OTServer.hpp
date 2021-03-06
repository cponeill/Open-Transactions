/************************************************************
 *    
 *  OTServer.h
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OTSERVER_HPP__
#define __OTSERVER_HPP__

#include "ExportWrapper.h"
#include "WinsockWrapper.h"
#include "TR1_Wrapper.hpp"

#ifndef IMPORT
#define IMPORT
#ifndef IMPORT_SET
#define IMPORT_SET
#endif
#endif

#include "OTAssetContract.hpp"
#include "OTPseudonym.hpp"
#include "OTAccount.hpp"
#include "OTCron.hpp"
#include "OTTransaction.hpp"

#ifdef IMPORT_SET
#undef IMPORT_SET
#ifdef IMPORT
#undef IMPORT
#include "ExportWrapper.h"
#endif
#endif

#include _CINTTYPES

#include <cstddef>

class OTMessage;
class OTClientConnection;
class OTPayment;
class OTMint;
class OTTrade;
class OTServerContract;
class OTAccount;
class OTAssetContract;
class OTIdentifier;
class OTTransaction;

// these correspond--same IDs.
typedef std::multimap<std::string, OTMint *>	mapOfMints;
typedef std::map<std::string, std::string>		mapOfBaskets;
typedef std::map<std::string, OTAccount *>		mapOfAccounts; // server side these are keyed by asset type ID

// Why does the map of mints use multimap instead of map?
// Because there might be multiple valid mints for the same asset type.
// Perhaps I am redeeming tokens from the previous series, which have not yet expired.
// Only tokens from the new series are being issued today, but tokens from the previous
// series are still good until their own expiration date, which is coming up soon.
// Therefore the server manages different mints for the same asset type, and since the asset
// type is the key in the multimap, we don't want to accidentally remove one from the list
// every time another is added. Thus multimap is employed.

class OTServer
{
	OTString	m_strWalletFilename;
	OTString	m_strConfigFilename;
	OTString	m_strLogFilename;

    bool        m_bReadOnly;        // Used at least for whether or not to write to the PID.
	bool		m_bShutdownFlag;	// If the server wants to be shut down, it can set this flag so the caller knows to do so.
	
	OTString	m_strVersion;		// Unused currently.
	OTString	m_strServerID;		// A hash of the server contract
	OTString	m_strServerUserID;	// A hash of the public key that signed the server contract.
	// -----------------------------------------------	
	OTServerContract * m_pServerContract; // This is the server's own contract, containing its public key and connect info.
	// -----------------------------------------------
	long			m_lTransactionNumber;	// This stores the last VALID AND ISSUED transaction number.
	
	OTPseudonym		m_nymServer; // the Nym for the server, so he can decrypt messages sent to him
								// by paranoid users :-P  UPDATE: By ALL users. Everything encrypted now by default.
	
	mapOfContracts	m_mapContracts;	// The asset types supported by this server.
	mapOfMints		m_mapMints;		// The mints for each asset type.

	OTAcctList		m_VoucherAccts;	// The list of voucher accounts (see GetVoucherAccount below for details)

	mapOfBaskets	m_mapBaskets;	// this map connects BASKET_ID with BASKET_ACCOUNT_ID (so you can look up the server's
									// basket issuer account ID, which is *different* on each server, using the Basket Currency's
									// ID, which is the *same* on every server.)
	mapOfBaskets	m_mapBasketContracts; // Need a way to look up a Basket Account ID using its Contract ID 
	
	// -------------------------------------------------------------------------------------------------------------
	
	OTCron			m_Cron;		// This is where re-occurring and expiring tasks go. 
	
	// -------------------------------------------------------------------------------------------------------------
	// From server.cfg:
	//
	static long			__min_market_scale;

    static int			__heartbeat_no_requests;	// The number of client requests that will be processed per heartbeat.
    static int			__heartbeat_ms_between_beats; // number of ms between each heartbeat.
	
	static std::string	__override_nym_id;	// The Nym who's allowed to do certain commands even if they are turned off.
	
	static bool			__admin_usage_credits; // Bool. Are usage credits REQUIRED in order to use this server?
	static bool			__admin_server_locked; // Bool. Is server currently locked to non-override Nyms?
    
	static bool			__cmd_usage_credits; // Bool. 
	static bool			__cmd_issue_asset; // Bool. 
	static bool			__cmd_get_contract; // Bool. 
	static bool			__cmd_check_server_id; // Bool. 
	
	static bool			__cmd_create_user_acct; // Bool. 
	static bool			__cmd_del_user_acct; // Bool. 
	static bool			__cmd_check_user; // Bool. 
	static bool			__cmd_get_request; // Bool. 
	static bool			__cmd_get_trans_num; // Bool. 
	static bool			__cmd_send_message; // Bool. 
	static bool			__cmd_get_nymbox; // Bool. 
	static bool			__cmd_process_nymbox; // Bool. 

	static bool			__cmd_create_asset_acct; // Bool. 
	static bool			__cmd_del_asset_acct; // Bool. 
	static bool			__cmd_get_acct; // Bool. 
	static bool			__cmd_get_inbox; // Bool. 
	static bool			__cmd_get_outbox; // Bool. 
	static bool			__cmd_process_inbox; // Bool. 

	static bool			__cmd_issue_basket; // Bool. 
	static bool			__transact_exchange_basket; // Bool. 

	static bool			__cmd_notarize_transaction; // Bool. 
	static bool			__transact_process_inbox; // Bool. 
	static bool			__transact_transfer; // Bool. 
	static bool			__transact_withdrawal; // Bool. 
	static bool			__transact_deposit; // Bool. 
	static bool			__transact_withdraw_voucher; // Bool. 
	static bool			__transact_deposit_cheque; // Bool. 
	static bool			__transact_pay_dividend; // Bool. 

	static bool			__cmd_get_mint; // Bool. 
	static bool			__transact_withdraw_cash; // Bool. 
	static bool			__transact_deposit_cash; // Bool. 

	static bool			__cmd_get_market_list; // Bool. 
	static bool			__cmd_get_market_offers; // Bool. 
	static bool			__cmd_get_market_recent_trades; // Bool. 
	static bool			__cmd_get_nym_market_offers; // Bool. 

	static bool			__transact_market_offer; // Bool. 
	static bool			__transact_payment_plan; // Bool. 
	static bool			__transact_cancel_cron_item; // Bool. 

	static bool			__transact_smart_contract; // Bool. 
	static bool			__cmd_trigger_clause; // Bool. 

public:
	// From server.cfg:
	
    static int      GetMinMarketScale() { return __min_market_scale; }
    static void     SetMinMarketScale(long lVal) { __min_market_scale = lVal; }

    static int      GetHeartbeatNoRequests() { return __heartbeat_no_requests; }
    static void     SetHeartbeatNoRequests(int nVal) { __heartbeat_no_requests = nVal; }
    
    static int      GetHeartbeatMsBetweenBeats() { return __heartbeat_ms_between_beats; }
    static void     SetHeartbeatMsBetweenBeats(int nVal) { __heartbeat_ms_between_beats = nVal; }
    
	// -----------------------------------------------
	
	static const std::string	&	GetOverrideNymID()  { return __override_nym_id; }
	static void						SetOverrideNymID(const std::string the_id) { __override_nym_id = the_id; }
	
	// -----------------------------------------------
	OTServer();
	virtual ~OTServer(); // Calls Release();
	
    // delete various dynamically allocated things such as the map of Mints, 
    // and the map of asset contracts.
    //
	virtual void Release();   
    
	void Release_Server();   

    // -----------------------
    
	inline bool IsFlaggedForShutdown() const { return m_bShutdownFlag; }
	
	// ---------------------------------------------------------------------------------

	// Obviously this will only work once the server contract has been loaded from storage.
	bool GetConnectInfo(OTString & strHostname, int & nPort);
	
	// Trade is passed in as reference to make sure it exists.
	// But the trade MUST be heap-allocated, as the market and cron
	// objects will own it and handle cleaning it up.
	// not needed -- erase this function.
//	bool AddTradeToMarket(OTTrade & theTrade);
	
	// ---------------------------------------------------------------------------------
	
	OTMint * GetMint(const OTIdentifier & ASSET_TYPE_ID, int nSeries); // Each asset contract has its own series of Mints
	
	// Whenever the server issues a voucher (like a cashier's cheque), it puts the funds in one
	// of these voucher accounts (one for each asset type ID). Then it issues the cheque from the
	// same account.
	// TODO: also should save the cheque itself to a folder, where the folder is named based on the date 
	// that the cheque will expire.  This way, the server operator can go back later, or have a script,
	// to retrieve the cheques from the expired folders, and total them. The server operator is free to
	// remove that total from the Voucher Account once the cheque has expired: it is his money now.
	//OTAccount * GetVoucherAccount(const OTIdentifier & ASSET_TYPE_ID);
	_SharedPtr<OTAccount> GetVoucherAccount(const OTIdentifier & ASSET_TYPE_ID);
	
	// When a user uploads an asset contract, the server adds it to the list (and verifies the user's key against the
	// contract.) This way the server has a directory with all the asset contracts that it supports, saved by their ID.
	// As long as the IDs are in the server file, it can look them up.
	// When a new asset type is added, a new Mint is added as well. It goes into the mints folder.
	bool	AddAssetContract(OTAssetContract & theContract);
	OTAssetContract * GetAssetContract(const OTIdentifier & ASSET_TYPE_ID);
	
	bool AddBasketAccountID(const OTIdentifier & BASKET_ID, const OTIdentifier & BASKET_ACCOUNT_ID,
							const OTIdentifier & BASKET_CONTRACT_ID);
	bool LookupBasketAccountID(const OTIdentifier & BASKET_ID, OTIdentifier & BASKET_ACCOUNT_ID);
	bool VerifyBasketAccountID(const OTIdentifier & BASKET_ACCOUNT_ID);

	bool LookupBasketAccountIDByContractID(const OTIdentifier & BASKET_CONTRACT_ID, OTIdentifier & BASKET_ACCOUNT_ID);
	bool LookupBasketContractIDByAccountID(const OTIdentifier & BASKET_ACCOUNT_ID, OTIdentifier & BASKET_CONTRACT_ID);

	const OTPseudonym & GetServerNym() const;
	
    // -------------------------------
    // Init():
    //
    // Loads the config file,
    // Initializes OTDB:: default storage,
    // Sets up the data folders,
    // Loads the main file,
    // and validates the server ID (for the Nym)
    //
	void Init(bool bReadOnly=false); // Loads the main file...
    // -------------------------------
	bool LoadConfigFile(); // loads the config file. (Called by Init.)
	// -------------------------------
	void ActivateCron();   // Starts up OT Cron, which processes recurring transactions,
                           // such as market offers, payment plans, and smart contracts.
                           // -------------------------------------------------------------
	void ProcessCron();    // Call this periodically, so Cron will have the chance to process its recurring transactions.
	// -------------------------------
    bool CreateMainFile(); // If the main file doesn't exist, OT will create it. (Asking you to paste some info.)
	bool LoadMainFile(bool bReadOnly=false); // Called in Init. Loads latest transaction number, and any other server data members.
    bool LoadServerUserAndContract(); // Called by LoadMainFile().
    // -------------------------------
	bool SaveMainFile();              // Called in IssueNextTransactionNumber.
	bool SaveMainFileToString(OTString & strMainFile);
    // -------------------------------
	bool ProcessUserCommand(OTMessage & theMessage, 
                            OTMessage & msgOut, 
                            OTClientConnection * pConnection=NULL, 
                            OTPseudonym * pNym=NULL);
    
	bool ValidateServerIDfromUser(OTString & strServerID);	
	// --------------------------------------------------------------
	// After EVERY / ANY transaction, plus certain messages, we drop a copy of the server's reply into
	// the Nymbox.  This way we are GUARANTEED that the Nym will receive and process it. (And thus
	// never get out of sync.)  This is the function used for doing that.
	//
	void DropReplyNoticeToNymbox(const OTIdentifier & SERVER_ID,
                                 const OTIdentifier & USER_ID,
                                 const OTString     & strMessage,
                                 const long         & lRequestNum,
                                 const bool           bReplyTransSuccess,
                                       OTPseudonym  * pActualNym=NULL);
    
    // Note: SendInstrumentToNym and SendMessageToNym CALL THIS. 
    // They are higher-level, this is lower-level.
    bool DropMessageToNymbox(const OTIdentifier & SERVER_ID,
                             const OTIdentifier & SENDER_USER_ID,
                             const OTIdentifier & RECIPIENT_USER_ID,
                             OTTransaction::transactionType theType,
                                   OTMessage    * pMsg=NULL,     
                             const OTString     * pstrMessage=NULL,
                             const char         * szCommand=NULL);
    
    // calls DropMessageToNymbox
    bool SendInstrumentToNym(const OTIdentifier & SERVER_ID,
                             const OTIdentifier & SENDER_USER_ID,
                             const OTIdentifier & RECIPIENT_USER_ID,
                                   OTMessage    * pMsg=NULL,       // the request msg from payer, which is attached WHOLE to the Nymbox receipt. contains payment already.
                             const OTPayment    * pPayment=NULL,   // or pass this instead: we will create our own msg here (with payment inside) to be attached to the receipt. 
                             const char         * szCommand=NULL); // for passing payDividend (as the message command instead of sendUserInstrument, the default.)
    
    // calls DropMessageToNymbox
    bool SendMessageToNym(const OTIdentifier & SERVER_ID,
                          const OTIdentifier & SENDER_USER_ID,
                          const OTIdentifier & RECIPIENT_USER_ID,
                                OTMessage    * pMsg=NULL,      // the request msg from payer, which is attached WHOLE to the Nymbox receipt. contains message already.
                          const OTString     * pstrMessage=NULL); // or pass this instead: we will create our own msg here (with message inside) to be attached to the receipt. 
    
	// --------------------------------------------------------------

	void UserCmdCheckServerID(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdCheckUser(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdSendUserMessage(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdSendUserInstrument(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetRequest(OTPseudonym & theNym, OTMessage & msgIn, OTMessage & msgOut);
	void UserCmdGetTransactionNum(OTPseudonym & theNym, OTMessage & msgIn, OTMessage & msgOut);
	void UserCmdIssueAssetType(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdIssueBasket(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetBoxReceipt(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdDeleteUser(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdDeleteAssetAcct(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdCreateAccount(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdNotarizeTransactions(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetNymbox(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetInbox(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);   // Deprecated (replaced by UserCmdGetAccountFiles)
	void UserCmdGetOutbox(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);  // Deprecated (replaced by UserCmdGetAccountFiles)
	void UserCmdGetAccount(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut); // Deprecated (replaced by UserCmdGetAccountFiles)
	void UserCmdGetAccountFiles(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut); // This combines GetInbox, GetOutbox, and GetAccount.
	void UserCmdGetContract(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetMint(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdProcessInbox(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdProcessNymbox(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	
	void UserCmdUsageCredits(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdTriggerClause(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);

	void UserCmdQueryAssetTypes(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);

	// Get the list of markets on this server.
	void UserCmdGetMarketList(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);

	// Get the publicly-available list of offers on a specific market.
	void UserCmdGetMarketOffers(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	
	// Get a report of recent trades that have occurred on a specific market.
	void UserCmdGetMarketRecentTrades(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	
	// Get the offers that a specific Nym has placed on a specific market.
	void UserCmdGetNym_MarketOffers(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	
	// Cancel a market offer. (CHANGING THIS INTO A TRANSACTION, INSTEAD OF A MESSAGE...)
//	void UserCmdCancelNymMarketOffer(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	// Exchange in/out of a basket currency. (CHANGING THIS INTO A TRANSACTION, INSTEAD OF A MESSAGE...)
//	void UserCmdExchangeBasket(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);

	bool IssueNextTransactionNumber(OTPseudonym & theNym, long &lTransactionNumber, bool bStoreTheNumber=true);
	bool VerifyTransactionNumber(OTPseudonym & theNym, const long &lTransactionNumber);	// Verify a transaction number. passed by reference for speed :P
	bool RemoveTransactionNumber(OTPseudonym & theNym, const long &lTransactionNumber, bool bSave=false);	// A nym has just used a transaction number. Remove it from his file.
	bool RemoveIssuedNumber(OTPseudonym & theNym, const long &lTransactionNumber, bool bSave=false); // a nym has just accepted a receipt. remove his responsibility for that number.

	// If the server receives a notarizeTransactions command, it will be accompanied by a payload
	// containing a ledger to be notarized.  UserCmdNotarizeTransactions will loop through that ledger,
	// and for each transaction within, it calls THIS method.
	void NotarizeTransaction(OTPseudonym & theNym, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	// ---------------------------------------------------------------------------------	
	void NotarizeTransfer(OTPseudonym & theNym, OTAccount & theFromAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	void NotarizeDeposit(OTPseudonym & theNym, OTAccount & theAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	void NotarizeWithdrawal(OTPseudonym & theNym, OTAccount & theAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	// ---------------------------------------------------------------------------------
	void NotarizeProcessInbox(OTPseudonym & theNym, OTAccount & theAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);	
	void NotarizeProcessNymbox(OTPseudonym & theNym, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	// ---------------------------------------------------------------------------------
	void NotarizeMarketOffer(OTPseudonym & theNym, OTAccount & theAssetAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	void NotarizePaymentPlan(OTPseudonym & theNym, OTAccount & theDepositorAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	void NotarizeSmartContract(OTPseudonym & theNym, OTAccount & theActivatingAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	// ---------------------------------------------------------------------------------
	void NotarizeCancelCronItem(OTPseudonym & theNym, OTAccount & theAssetAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	void NotarizeExchangeBasket(OTPseudonym & theNym, OTAccount & theSourceAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
	// ---------------------------------------------------------------------------------
    void NotarizePayDividend(OTPseudonym & theNym, OTAccount & theAccount, OTTransaction & tranIn, OTTransaction & tranOut, bool & bOutSuccess);
};


// Note: from OTAssetContract.h and .cpp.
// This is a subclass of OTAcctFunctor, which is used whenever OTAssetContract needs to
// loop through all the accounts for a given asset type (its own.) This subclass needs to
// call OTServer method to do its job, so it can't be defined in otlib, but must be defined
// here in otserver (so it can see the methods that it needs...)
//
class OTAcctFunctor_PayDividend : public OTAcctFunctor
{
    OTIdentifier  * m_pUserID;
    OTIdentifier  * m_pPayoutAssetID;
    OTIdentifier  * m_pVoucherAcctID;
    OTString      * m_pstrMemo; // contains the original payDividend item from the payDividend transaction request. (Stored in the memo field for each voucher.)
    OTServer      * m_pServer;  // no need to cleanup. It's here for convenience only.
    long            m_lPayoutPerShare;
    long            m_lAmountPaidOut;  // as we pay each voucher out, we keep a running count.
    long            m_lAmountReturned; // as we pay each voucher out, we keep a running count.
        
public:
    OTAcctFunctor_PayDividend(const OTIdentifier  & theServerID, 
                              const OTIdentifier  & theUserID, 
                              const OTIdentifier  & thePayoutAssetID,
                              const OTIdentifier  & theVoucherAcctID,
                              const OTString      & strMemo,
                                    OTServer      & theServer, 
                                    long            lPayoutPerShare,
                                    mapOfAccounts * pLoadedAccounts=NULL);
    virtual ~OTAcctFunctor_PayDividend();
    
    OTIdentifier  * GetUserID()         { return m_pUserID;         }
    OTIdentifier  * GetPayoutAssetID()  { return m_pPayoutAssetID;  }
    OTIdentifier  * GetVoucherAcctID()  { return m_pVoucherAcctID;  }
    OTString      * GetMemo()           { return m_pstrMemo;        }
    OTServer      * GetServer()         { return m_pServer;         }
    long            GetPayoutPerShare() { return m_lPayoutPerShare; }
    long            GetAmountPaidOut()  { return m_lAmountPaidOut;  }
    long            GetAmountReturned() { return m_lAmountReturned; }
    
    virtual bool Trigger(OTAccount & theAccount);
};


#endif // __OTSERVER_HPP__

















