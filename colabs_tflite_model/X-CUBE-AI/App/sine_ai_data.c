/**
  ******************************************************************************
  * @file    sine_ai_data.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Dec  7 13:30:20 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
#include "sine_ai_data.h"
#include "ai_platform_interface.h"


AI_ALIGNED(32)
const ai_u64 s_sine_ai_weights_array_u64[ 161 ] = {
  0xbe7b0568be2c4f7cU, 0xbe2ac36abf0d2210U, 0x3e84bf883d44cf3fU, 0xbda5b878be29bdfaU,
  0x3f290779bec41fb4U, 0xbf068febbe51d040U, 0xbed5ed083ed5438fU, 0x3ed2dfc83ef6fb20U,
  0x0U, 0x0U, 0x3e8e3ab83e94898dU, 0x0U,
  0xbf9a53a000000000U, 0x0U, 0x3e5c1a0fU, 0xbce89e04bf763f0cU,
  0xbecbfb433d841d44U, 0xbe964e943e84e961U, 0x3df06d863d94f6efU, 0x3e53290ebec9d417U,
  0xbcafbe6b3e23b47aU, 0xbe6068ccbeb2a820U, 0xbca6a880bf83adebU, 0xbdfb2e7cbf1e09e2U,
  0xbe434788be471082U, 0xbd778dc8becd5d93U, 0xbeba6dcfbcd50c44U, 0x3e37818ebe184436U,
  0x3ebdd948bdf625f4U, 0xbec3fa1cbe3da86aU, 0x3c6b62803efe28f4U, 0x3e1b5afb3e89d79bU,
  0x3db554bc3e2c5b26U, 0x3e8688c3bbb85780U, 0xbe2fb532bea23340U, 0xbed0c8343e4a276eU,
  0xbde276e0bdc34a3cU, 0x3e8d69bd3d999154U, 0xbe242c443e2cccdeU, 0xbd336da8bc9814a0U,
  0xbd1f95703e13f99aU, 0x3ed370333e9802b1U, 0x3eb216d83e90a205U, 0x3e2b1d82beaf087eU,
  0xbdd93cddbe8ff782U, 0xbe95f95ebe97ee68U, 0xbcf11ab03e1b99b5U, 0x3d6c27ea3dde7fa4U,
  0xbea1130a3d5cc5c8U, 0x3e22cc8ebdc180a8U, 0x3dc5c12e3d0f55efU, 0x3ed0b0fdbe18a6f0U,
  0x3eb13a2f3e28de96U, 0xbe39af44be2b5012U, 0x3e365cb2bc658b09U, 0x3e114bf4bbe21d06U,
  0x3e6958523d7ec4b0U, 0x3e6df58ebcf0be80U, 0xbe9f5e02be3599f2U, 0x3e23847a3e9dad13U,
  0xbe35c4a83eb4ac2fU, 0x3e982e4dbe8efad2U, 0xbe4d2b8cbe26a376U, 0x3e8ebf473c687aa0U,
  0xbe976fc03e5cb25eU, 0xbbc8a5c03ec284c5U, 0x3eabf684be5d531bU, 0xbe37f870bed957afU,
  0xbe0df1023e9e7711U, 0x3e0ab426be1e7818U, 0x3c4298003e826dc9U, 0x3c7d2e613e674b44U,
  0x3ea2ad8dbe11bd0cU, 0xbd9e36fcbed895dbU, 0xbdc177733e7e462dU, 0x3e35a736be0a1bfaU,
  0xbeaafadf3e23a0deU, 0xbd45b1f83d7f8e78U, 0xbe2efe78bd9e21f0U, 0xbd11e70dbe2afb62U,
  0x3e220d2ebecf2efbU, 0x3e55284a3e4cb942U, 0x3ea798cc3e975fd8U, 0xbea2495d3ebe1817U,
  0xbc8a3528beb0674dU, 0x3e3ba67abec6f296U, 0x3e1773ca3e17d6c3U, 0x3e46a0f3bec473ebU,
  0x3db6debc3ebaf699U, 0xbe03962c3ebcfb6dU, 0xbedbaa85bd64afc0U, 0x3e9be0e53dfaf39cU,
  0x3e40ccf23ed40e01U, 0xbd9cb72c3ea3dbe7U, 0xbea19ed3bd794438U, 0xbda065a03e26d896U,
  0x3dcf43cc3e97467dU, 0xbdea79943ebc68e7U, 0x3e550a403e1c9addU, 0xbe90d4fc3e30a4baU,
  0x3bad01f4bed09668U, 0xbd540510be147440U, 0xbe99a2e83dc34122U, 0x3eadb892bc9e70f3U,
  0x3e3d2e32be27ff94U, 0x3db73b9cbedacd9eU, 0xbd4467953e59b6feU, 0x3e925debbedd931bU,
  0x3e052ff9bec0cc43U, 0xbea3f38e3d37e670U, 0x3e92b21b3ec7d739U, 0x3e27b752be108e8cU,
  0x3eaa416bbe9e14d7U, 0x3d174a483d3f0890U, 0x3e4c8e57becf4b14U, 0xbedb2d2d3ea9b3cfU,
  0x3e35dfc5be681afaU, 0xbecabe8a3df60c24U, 0x3e8241713e28cbeeU, 0x3e9330e13ee085ccU,
  0xbe3759bcbe7ead81U, 0x3ea9164dbb65c480U, 0xbdc2b77c3ec6fd15U, 0x3d7ed350be9ff53aU,
  0x3d9f0f46beacbc92U, 0x3e0385dabecc0a59U, 0xbe18aa663e60e72dU, 0x3edfb4acbebb41f6U,
  0xbebd4bc73ec826a9U, 0xbe4d021dbe0a9ff0U, 0xbd9b66e6be9c0d50U, 0xbdc884303e7c84beU,
  0x3f1f2a553ec90109U, 0x3e0f034e3d9ebba4U, 0xbc8ca120be86551cU, 0x3d491c4e3f3987bbU,
  0xbe57d4113e4b40faU, 0x3eb87c13bdfaae1cU, 0xbebe61793c0e2ac0U, 0x3eb1694f3ebb85dbU,
  0xbed3bf663ecb9eddU, 0x3ec98e13bec7de1bU, 0xbd3b0828be0a2110U, 0xbe83618ebe4f6ab2U,
  0xbe89e5f23f119f43U, 0x3dd8cd7d00000000U, 0xbe5b79b3U, 0xbd177fd7be9cd177U,
  0x3e0adf98U, 0xbec9f3893e06676eU, 0x3e0abec2bea3b3b7U, 0xbfab2290U,
  0xbf149f73bfa581deU, 0x3d0639b73ee4901cU, 0xbee52d24bedbd577U, 0x3ee62688be98144eU,
  0xbf01adb03f06b416U, 0xbed1fc2c3e6827efU, 0x3f1468f7bf30d78cU, 0xbe8dc36240148b20U,
  0x3e0ca6baU,
};



AI_API_DECLARE_BEGIN

/*!
 * @brief Get network weights array pointer as a handle ptr.
 * @ingroup sine_ai_data
 * @return a ai_handle pointer to the weights array
 */
AI_DEPRECATED
AI_API_ENTRY
ai_handle ai_sine_ai_data_weights_get(void)
{
  static const ai_u8* const s_sine_ai_weights_map[1 + 2] = {
    AI_PTR(AI_MAGIC_MARKER),
    AI_PTR(s_sine_ai_weights_array_u64),
    AI_PTR(AI_MAGIC_MARKER)
  };

  return AI_HANDLE_PTR(s_sine_ai_weights_map);

}


/*!
 * @brief Get network params configuration data structure.
 * @ingroup sine_ai_data
 * @return true if a valid configuration is present, false otherwise
 */
AI_API_ENTRY
ai_bool ai_sine_ai_data_params_get(ai_handle network, ai_network_params* params)
{
  if (!(network && params)) return false;
  
  static ai_buffer s_sine_ai_data_map_activations[AI_SINE_AI_DATA_ACTIVATIONS_COUNT] = {
    AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8, 1, 1, AI_SINE_AI_DATA_ACTIVATIONS_SIZE, 1, NULL)
  };

  const ai_buffer_array map_activations = 
    AI_BUFFER_ARRAY_OBJ_INIT(AI_FLAG_NONE, AI_SINE_AI_DATA_ACTIVATIONS_COUNT, s_sine_ai_data_map_activations);
  
  static ai_buffer s_sine_ai_data_map_weights[AI_SINE_AI_DATA_WEIGHTS_COUNT] = {
    AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8, 1, 1, 1288, 1, s_sine_ai_weights_array_u64),
    
  };

  const ai_buffer_array map_weights = 
    AI_BUFFER_ARRAY_OBJ_INIT(AI_FLAG_NONE, AI_SINE_AI_DATA_WEIGHTS_COUNT, s_sine_ai_data_map_weights);

  return ai_platform_bind_network_params(network, params, &map_weights, &map_activations);
}


AI_API_DECLARE_END
