/*********************************************************************************************************************
* TC264 Opensourec Library 即（TC264 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
*
* 本文件是 TC264 开源库的一部分
*
* TC264 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
*
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
*
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
*
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
*
* 文件名称          zf_device_camera
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          ADS v1.10.2
* 适用平台          TC264D
* 店铺链接          https://seekfree.taobao.com/
*
* 修改记录
* 日期              作者                备注
* 2022-09-15       pudding            first version
* 2023-04-25       pudding            增加中文注释说明
********************************************************************************************************************/

#ifndef _zf_device_camera_h_
#define _zf_device_camera_h_

#include "zf_common_fifo.h"
#include "zf_common_typedef.h"
#include "zf_driver_uart.h"
#include "zf_device_type.h"

//=================================================摄像头公共库 基本配置================================================
#define CAMERA_RECEIVER_BUFFER_SIZE     (8)         // 定义摄像头接收数据缓冲区大小
extern fifo_struct camera_receiver_fifo;            // 声明摄像头接收数据fifo结构体
extern uint8 camera_send_image_frame_header[4];     // 声明摄像头数据发送到上位机的帧头
//=================================================摄像头公共库 基本配置================================================

//=================================================摄像头公共库 基础函数================================================
void  camera_binary_image_decompression (const uint8 *data1, uint8 *data2, uint32 image_size);                  // 摄像头二进制图像数据解压为十六进制八位数据 小钻风用
void  camera_send_image                 (uart_index_enum uartn, const uint8 *image_addr, uint32 image_size);    // 摄像头图像发送至上位机查看图像
void  camera_fifo_init                  (void);                                                                 // 摄像头串口 FIFO 初始化
uint8 camera_init                       (uint8 *source_addr, uint8 *destination_addr, uint32 image_size);       // 摄像头采集初始化
uint8 camera_init_2                     (uint8 *source_addr, uint8 *destination_addr, uint32 image_size);       // 摄像头2采集初始化
//=================================================摄像头公共库 基础函数================================================

#endif
