

#ifndef _ATCSDINTERFACE_H_
#define _ATCSDINTERFACE_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "ImmInterface.h"
#include "product_config.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
#if(FEATURE_ON == FEATURE_CSD)


/*****************************************************************************
  3 枚举定义
*****************************************************************************/


enum AT_CSD_MSG_ID_ENUM
{
    ID_AT_CSD_CALL_STATE_IND            = 0X0001,                               /*当前通话状态指示*/
    ID_AT_CSD_MSG_ID_ENUM_BUTT
};
typedef VOS_UINT32 AT_CSD_MSG_ID_ENUM_UINT32;
enum AT_CSD_CALL_TYPE_STATE
{
    AT_CSD_CALL_STATE_ON                = 0X0001,                               /*当前通话为接通状态*/
    AT_CSD_CALL_STATE_OFF                       ,                               /*当前通话为挂断状态*/
    AT_CSD_CALL_STATE_BUTT
};
typedef VOS_UINT16 AT_CSD_CALL_TYPE_STATE_ENUM_UINT16;

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


typedef struct
{
    VOS_MSG_HEADER                                                              /*消息头*/
    AT_CSD_MSG_ID_ENUM_UINT32           enMsgId;                                /*消息ID*/
    AT_CSD_CALL_TYPE_STATE_ENUM_UINT16  enCallState;                            /*电话是否接通*/
    VOS_UINT8                           ucIndex;
    VOS_UINT8                           aucReserved[1];
}AT_CSD_CALL_STATE_TYPE_IND_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/



extern VOS_VOID CSD_UL_SendData(IMM_ZC_STRU *pstULData);



#endif/*FEATURE_CSD*/

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of CsdInterface.h */

