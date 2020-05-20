#pragma once

#ifndef _CFG_OP_H_
#ifdef _CFG_OP_H

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus

	//获取配置项
	int GetCfgItem(char* pFileName/*in*/, char* pKey/*in*/, char* pValue/*out*/, int* pValueLen/*out*/);

	//写入配置项
	int WriteCfgItem(char* pFileName/*in*/, char* pKey/*in*/, char* pValue/*in*/, int itemValueLen/*in*/);

#ifdef _cplusplus
}
#endif // _cplusplus


#endif // _CFG_OP_H

#endif // !_CFG_OP_H_


