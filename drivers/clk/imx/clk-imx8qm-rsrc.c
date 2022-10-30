// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2019-2021 NXP
 *	Dong Aisheng <aisheng.dong@nxp.com>
 */

#include <dt-bindings/firmware/imx/rsrc.h>

#include "clk-scu.h"

/* Keep sorted in the ascending order */
static const u32 imx8qm_clk_scu_rsrc_table[] = {
	IMX_SC_R_A53,
	IMX_SC_R_A72,
	IMX_SC_R_DC_0_VIDEO0,
	IMX_SC_R_DC_0_VIDEO1,
	IMX_SC_R_DC_0,
	IMX_SC_R_DC_0_PLL_0,
	IMX_SC_R_DC_0_PLL_1,
	IMX_SC_R_DC_1_VIDEO0,
	IMX_SC_R_DC_1_VIDEO1,
	IMX_SC_R_DC_1,
	IMX_SC_R_DC_1_PLL_0,
	IMX_SC_R_DC_1_PLL_1,
	IMX_SC_R_SPI_0,
	IMX_SC_R_SPI_1,
	IMX_SC_R_SPI_2,
	IMX_SC_R_SPI_3,
	IMX_SC_R_UART_0,
	IMX_SC_R_UART_1,
	IMX_SC_R_UART_2,
	IMX_SC_R_UART_3,
	IMX_SC_R_UART_4,
	IMX_SC_R_EMVSIM_0,
	IMX_SC_R_EMVSIM_1,
	IMX_SC_R_I2C_0,
	IMX_SC_R_I2C_1,
	IMX_SC_R_I2C_2,
	IMX_SC_R_I2C_3,
	IMX_SC_R_I2C_4,
	IMX_SC_R_ADC_0,
	IMX_SC_R_ADC_1,
	IMX_SC_R_FTM_0,
	IMX_SC_R_FTM_1,
	IMX_SC_R_CAN_0,
	IMX_SC_R_GPU_0_PID0,
	IMX_SC_R_GPU_1_PID0,
	IMX_SC_R_PWM_0,
	IMX_SC_R_PWM_1,
	IMX_SC_R_PWM_2,
	IMX_SC_R_PWM_3,
	IMX_SC_R_PWM_4,
	IMX_SC_R_PWM_5,
	IMX_SC_R_PWM_6,
	IMX_SC_R_PWM_7,
	IMX_SC_R_GPT_0,
	IMX_SC_R_GPT_1,
	IMX_SC_R_GPT_2,
	IMX_SC_R_GPT_3,
	IMX_SC_R_GPT_4,
	IMX_SC_R_FSPI_0,
	IMX_SC_R_FSPI_1,
	IMX_SC_R_SDHC_0,
	IMX_SC_R_SDHC_1,
	IMX_SC_R_SDHC_2,
	IMX_SC_R_ENET_0,
	IMX_SC_R_ENET_1,
	IMX_SC_R_MLB_0,
	IMX_SC_R_USB_2,
	IMX_SC_R_NAND,
	IMX_SC_R_LVDS_0,
	IMX_SC_R_LVDS_0_PWM_0,
	IMX_SC_R_LVDS_0_I2C_0,
	IMX_SC_R_LVDS_0_I2C_1,
	IMX_SC_R_LVDS_1,
	IMX_SC_R_LVDS_1_PWM_0,
	IMX_SC_R_LVDS_1_I2C_0,
	IMX_SC_R_LVDS_1_I2C_1,
	IMX_SC_R_M4_0_I2C,
	IMX_SC_R_M4_1_I2C,
	IMX_SC_R_AUDIO_PLL_0,
	IMX_SC_R_VPU_UART,
	IMX_SC_R_VPUCORE,
	IMX_SC_R_MIPI_0,
	IMX_SC_R_MIPI_0_PWM_0,
	IMX_SC_R_MIPI_0_I2C_0,
	IMX_SC_R_MIPI_0_I2C_1,
	IMX_SC_R_MIPI_1,
	IMX_SC_R_MIPI_1_PWM_0,
	IMX_SC_R_MIPI_1_I2C_0,
	IMX_SC_R_MIPI_1_I2C_1,
	IMX_SC_R_CSI_0,
	IMX_SC_R_CSI_0_PWM_0,
	IMX_SC_R_CSI_0_I2C_0,
	IMX_SC_R_CSI_1,
	IMX_SC_R_CSI_1_PWM_0,
	IMX_SC_R_CSI_1_I2C_0,
	IMX_SC_R_HDMI,
	IMX_SC_R_HDMI_I2S,
	IMX_SC_R_HDMI_I2C_0,
	IMX_SC_R_HDMI_PLL_0,
	IMX_SC_R_HDMI_RX,
	IMX_SC_R_HDMI_RX_BYPASS,
	IMX_SC_R_HDMI_RX_I2C_0,
	IMX_SC_R_AUDIO_PLL_1,
	IMX_SC_R_AUDIO_CLK_0,
	IMX_SC_R_AUDIO_CLK_1,
	IMX_SC_R_HDMI_RX_PWM_0,
	IMX_SC_R_HDMI_PLL_1,
	IMX_SC_R_VPU,
};

const struct imx_clk_scu_rsrc_table imx_clk_scu_rsrc_imx8qm = {
	.rsrc = imx8qm_clk_scu_rsrc_table,
	.num = ARRAY_SIZE(imx8qm_clk_scu_rsrc_table),
};
