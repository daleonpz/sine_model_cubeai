/**
  ******************************************************************************
  * @file    autoencoder_model.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Jan 13 18:06:57 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "autoencoder_model.h"
#include "autoencoder_model_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"




#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_autoencoder_model
 
#undef AI_AUTOENCODER_MODEL_MODEL_SIGNATURE
#define AI_AUTOENCODER_MODEL_MODEL_SIGNATURE     "7788e932ca191380e53e90f3775d2455"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Thu Jan 13 18:06:57 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_AUTOENCODER_MODEL_N_BATCHES
#define AI_AUTOENCODER_MODEL_N_BATCHES         (1)




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_dense_6_input0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 400, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  dense_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  nl_0_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  nl_1_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  nl_2_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  nl_3_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  nl_4_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  nl_5_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  dense_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  nl_6_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  dense_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 400, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  nl_8_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 400, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  dense_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 51200, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  dense_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  dense_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  dense_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  dense_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 51200, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  dense_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 400, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_dense_6_input0_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 400, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1600, 1600),
  1, &serving_default_dense_6_input0_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  dense_0_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_0_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  nl_0_nl_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &nl_0_nl_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_1_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  nl_1_nl_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &nl_1_nl_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &dense_2_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  nl_2_nl_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_2_nl_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_3_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_3_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  nl_3_nl_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &nl_3_nl_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &dense_4_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  nl_4_nl_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_4_nl_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_output, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_5_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  nl_5_nl_output, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &nl_5_nl_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  dense_6_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_6_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  nl_6_nl_output, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &nl_6_nl_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  dense_7_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 400, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1600, 1600),
  1, &dense_7_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  nl_8_output, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 400, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1600, 1600),
  1, &nl_8_output_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  dense_0_weights, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 400, 128, 1, 1), AI_STRIDE_INIT(4, 4, 1600, 204800, 204800),
  1, &dense_0_weights_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  dense_0_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_0_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_weights, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 128, 64, 1, 1), AI_STRIDE_INIT(4, 4, 512, 32768, 32768),
  1, &dense_1_weights_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_1_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_weights, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 64, 32, 1, 1), AI_STRIDE_INIT(4, 4, 256, 8192, 8192),
  1, &dense_2_weights_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &dense_2_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  dense_3_weights, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 32, 8, 1, 1), AI_STRIDE_INIT(4, 4, 128, 1024, 1024),
  1, &dense_3_weights_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  dense_3_bias, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_3_bias_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_weights, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 8, 32, 1, 1), AI_STRIDE_INIT(4, 4, 32, 1024, 1024),
  1, &dense_4_weights_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &dense_4_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_weights, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 32, 64, 1, 1), AI_STRIDE_INIT(4, 4, 128, 8192, 8192),
  1, &dense_5_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_5_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  dense_6_weights, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 64, 128, 1, 1), AI_STRIDE_INIT(4, 4, 256, 32768, 32768),
  1, &dense_6_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  dense_6_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_6_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  dense_7_weights, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 128, 400, 1, 1), AI_STRIDE_INIT(4, 4, 512, 204800, 204800),
  1, &dense_7_weights_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  dense_7_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 400, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1600, 1600),
  1, &dense_7_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_8_layer, 8,
  NL_TYPE, 0x0, NULL,
  nl, forward_sigmoid,
  &nl_8_chain,
  NULL, &nl_8_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_6_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_7_weights, &dense_7_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_7_layer, 7,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_7_chain,
  NULL, &nl_8_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_6_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_6_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_6_nl_layer, 6,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_6_nl_chain,
  NULL, &dense_7_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_5_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_6_weights, &dense_6_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_6_layer, 6,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_6_chain,
  NULL, &nl_6_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_5_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_5_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_5_nl_layer, 5,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_5_nl_chain,
  NULL, &dense_6_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_4_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_5_weights, &dense_5_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_5_layer, 5,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_5_chain,
  NULL, &nl_5_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_4_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_4_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_4_nl_layer, 4,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_4_nl_chain,
  NULL, &dense_5_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_3_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_4_weights, &dense_4_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_4_layer, 4,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_4_chain,
  NULL, &nl_4_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_3_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_3_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_3_nl_layer, 3,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_3_nl_chain,
  NULL, &dense_4_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_2_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_3_weights, &dense_3_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_3_layer, 3,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_3_chain,
  NULL, &nl_3_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_2_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_2_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_2_nl_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_2_nl_chain,
  NULL, &dense_3_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_1_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_2_weights, &dense_2_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_2_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_2_chain,
  NULL, &nl_2_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_1_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_1_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_1_nl_layer, 1,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_1_nl_chain,
  NULL, &dense_2_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_0_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_1_weights, &dense_1_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_layer, 1,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_1_chain,
  NULL, &nl_1_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_0_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_0_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_0_nl_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_0_nl_chain,
  NULL, &dense_1_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_dense_6_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_0_weights, &dense_0_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_0_layer, 0,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_0_chain,
  NULL, &nl_0_nl_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 496992, 1, 1),
    496992, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2112, 1, 1),
    2112, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUTOENCODER_MODEL_IN_NUM, &serving_default_dense_6_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUTOENCODER_MODEL_OUT_NUM, &nl_8_output),
  &dense_0_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 496992, 1, 1),
      496992, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 2112, 1, 1),
      2112, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUTOENCODER_MODEL_IN_NUM, &serving_default_dense_6_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUTOENCODER_MODEL_OUT_NUM, &nl_8_output),
  &dense_0_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool autoencoder_model_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  ai_ptr activations_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_activations_map(activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    dense_0_output_array.data = AI_PTR(activations_map[0] + 1344);
    dense_0_output_array.data_start = AI_PTR(activations_map[0] + 1344);
    nl_0_nl_output_array.data = AI_PTR(activations_map[0] + 1344);
    nl_0_nl_output_array.data_start = AI_PTR(activations_map[0] + 1344);
    dense_1_output_array.data = AI_PTR(activations_map[0] + 1856);
    dense_1_output_array.data_start = AI_PTR(activations_map[0] + 1856);
    nl_1_nl_output_array.data = AI_PTR(activations_map[0] + 1344);
    nl_1_nl_output_array.data_start = AI_PTR(activations_map[0] + 1344);
    dense_2_output_array.data = AI_PTR(activations_map[0] + 1600);
    dense_2_output_array.data_start = AI_PTR(activations_map[0] + 1600);
    nl_2_nl_output_array.data = AI_PTR(activations_map[0] + 1344);
    nl_2_nl_output_array.data_start = AI_PTR(activations_map[0] + 1344);
    dense_3_output_array.data = AI_PTR(activations_map[0] + 1472);
    dense_3_output_array.data_start = AI_PTR(activations_map[0] + 1472);
    nl_3_nl_output_array.data = AI_PTR(activations_map[0] + 1344);
    nl_3_nl_output_array.data_start = AI_PTR(activations_map[0] + 1344);
    dense_4_output_array.data = AI_PTR(activations_map[0] + 1376);
    dense_4_output_array.data_start = AI_PTR(activations_map[0] + 1376);
    nl_4_nl_output_array.data = AI_PTR(activations_map[0] + 1504);
    nl_4_nl_output_array.data_start = AI_PTR(activations_map[0] + 1504);
    dense_5_output_array.data = AI_PTR(activations_map[0] + 1632);
    dense_5_output_array.data_start = AI_PTR(activations_map[0] + 1632);
    nl_5_nl_output_array.data = AI_PTR(activations_map[0] + 1344);
    nl_5_nl_output_array.data_start = AI_PTR(activations_map[0] + 1344);
    dense_6_output_array.data = AI_PTR(activations_map[0] + 1600);
    dense_6_output_array.data_start = AI_PTR(activations_map[0] + 1600);
    nl_6_nl_output_array.data = AI_PTR(activations_map[0] + 1600);
    nl_6_nl_output_array.data_start = AI_PTR(activations_map[0] + 1600);
    dense_7_output_array.data = AI_PTR(activations_map[0] + 0);
    dense_7_output_array.data_start = AI_PTR(activations_map[0] + 0);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool autoencoder_model_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  ai_ptr weights_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_weights_map(weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    dense_0_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_0_weights_array.data = AI_PTR(weights_map[0] + 0);
    dense_0_weights_array.data_start = AI_PTR(weights_map[0] + 0);
    dense_0_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_0_bias_array.data = AI_PTR(weights_map[0] + 204800);
    dense_0_bias_array.data_start = AI_PTR(weights_map[0] + 204800);
    dense_1_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_1_weights_array.data = AI_PTR(weights_map[0] + 205312);
    dense_1_weights_array.data_start = AI_PTR(weights_map[0] + 205312);
    dense_1_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_1_bias_array.data = AI_PTR(weights_map[0] + 238080);
    dense_1_bias_array.data_start = AI_PTR(weights_map[0] + 238080);
    dense_2_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_2_weights_array.data = AI_PTR(weights_map[0] + 238336);
    dense_2_weights_array.data_start = AI_PTR(weights_map[0] + 238336);
    dense_2_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_2_bias_array.data = AI_PTR(weights_map[0] + 246528);
    dense_2_bias_array.data_start = AI_PTR(weights_map[0] + 246528);
    dense_3_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_3_weights_array.data = AI_PTR(weights_map[0] + 246656);
    dense_3_weights_array.data_start = AI_PTR(weights_map[0] + 246656);
    dense_3_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_3_bias_array.data = AI_PTR(weights_map[0] + 247680);
    dense_3_bias_array.data_start = AI_PTR(weights_map[0] + 247680);
    dense_4_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_4_weights_array.data = AI_PTR(weights_map[0] + 247712);
    dense_4_weights_array.data_start = AI_PTR(weights_map[0] + 247712);
    dense_4_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_4_bias_array.data = AI_PTR(weights_map[0] + 248736);
    dense_4_bias_array.data_start = AI_PTR(weights_map[0] + 248736);
    dense_5_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_5_weights_array.data = AI_PTR(weights_map[0] + 248864);
    dense_5_weights_array.data_start = AI_PTR(weights_map[0] + 248864);
    dense_5_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_5_bias_array.data = AI_PTR(weights_map[0] + 257056);
    dense_5_bias_array.data_start = AI_PTR(weights_map[0] + 257056);
    dense_6_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_6_weights_array.data = AI_PTR(weights_map[0] + 257312);
    dense_6_weights_array.data_start = AI_PTR(weights_map[0] + 257312);
    dense_6_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_6_bias_array.data = AI_PTR(weights_map[0] + 290080);
    dense_6_bias_array.data_start = AI_PTR(weights_map[0] + 290080);
    dense_7_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_7_weights_array.data = AI_PTR(weights_map[0] + 290592);
    dense_7_weights_array.data_start = AI_PTR(weights_map[0] + 290592);
    dense_7_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_7_bias_array.data = AI_PTR(weights_map[0] + 495392);
    dense_7_bias_array.data_start = AI_PTR(weights_map[0] + 495392);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_autoencoder_model_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_AUTOENCODER_MODEL_MODEL_NAME,
      .model_signature   = AI_AUTOENCODER_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 128704,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_autoencoder_model_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_AUTOENCODER_MODEL_MODEL_NAME,
      .model_signature   = AI_AUTOENCODER_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 128704,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_autoencoder_model_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_autoencoder_model_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_autoencoder_model_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_autoencoder_model_create(network, AI_AUTOENCODER_MODEL_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_autoencoder_model_data_params_get(&params) != true) {
        err = ai_autoencoder_model_get_error(*network);
        return err;
    }
#if defined(AI_AUTOENCODER_MODEL_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_AUTOENCODER_MODEL_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_autoencoder_model_init(*network, &params) != true) {
        err = ai_autoencoder_model_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_autoencoder_model_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_autoencoder_model_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_autoencoder_model_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_autoencoder_model_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= autoencoder_model_configure_weights(net_ctx, params);
  ok &= autoencoder_model_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_autoencoder_model_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_autoencoder_model_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_AUTOENCODER_MODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME
