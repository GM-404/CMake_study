#include <iostream>

/* 常数（请勿修改） ----------------------------------------*/
#define FMCW_RISE_STEP (12.02e-9)        ///< FMCW上升时间步长,单位s
#define WAVE_LENGTH (0.0124266303834197) ///< 波长
#define ADC_SAMPLE_RATE (10.4e6)         ///< ADC采样率
#define NUM_TX_ANTENNA (1)               ///< 发射天线数量
#define NUM_RX_ANTENNA (2)               ///< 接收天线数量

/* 参数设置 ========================================*/

// #define FMCW_RISE_STEP_FREQ_KHZ (103U) ///< FMCW上升频率步长,单位KHz
#define FMCW_RISE_STEP_FREQ_KHZ (363U) ///< FMCW上升频率步长,单位KHz
#define FMCW_RISE_STEP_NUM (2620U)     ///< FMCW上升频率步数, 步长FMCW_RISE_STEP
// #define COHERENT_CHIRP_GAP (1120U)     ///< 相干组中chirp间隔，步长FMCW_RISE_STEP
#define COHERENT_CHIRP_GAP (770U) ///< 相干组中chirp间隔，步长FMCW_RISE_STEP

#define RX_ANTENNA_SPACING (6.25e-3) ///< 接收天线间距

#define NUM_SAMPLE (256)          ///< 采样点
#define NUM_COHERENT_CHIRP (8)    ///< 相干累加的chirp数
#define NUM_CHIRP (64)            ///< 帧内chirp数量
#define NUM_RANGEBIN (45)         ///< 一阶FFT输出Range Bin数量，一般根据最大测距范围设定
#define COHE_ACC_SCALE_FACTOR 110 ///< 相干累加后数据的缩放倍数的分子，分母为16。即当该参数设置为8时，相干累加后数据的缩放倍数为8/16 = 0.5

#define MAX_SPEED_RANGE (2.325827952) ///< 最大测速，自动计算Chirp周期

#define TIME_FRAME_FULL (200e-3) ///< 帧时长
// 6.5号测量马桶更改
//  #define STATIC_CLUTTER_UPDATE_PERIOD (2.0)                                           ///< 静态杂波更新周期，单位：s
//  #define STATIC_CLUTTER_UPDATE_WEIGHT ((uint32_t)(0.1 * (double)((uint64_t)1 << 31))) ///< 静态杂波更新权重，越大对慢速目标抑制越快

#define STATIC_CLUTTER_UPDATE_PERIOD (0.3)                                           ///< 静态杂波更新周期，单位：s
#define STATIC_CLUTTER_UPDATE_WEIGHT ((uint32_t)(0.7 * (double)((uint64_t)1 << 31))) ///< 静态杂波更新权重，越大对慢速目标抑制越快
// 计算一些次生参数
#define BANDWIDTH ((double)(NUM_SAMPLE * FMCW_RISE_STEP_FREQ_KHZ * 1000) / (ADC_SAMPLE_RATE * FMCW_RISE_STEP)) ///< 等效带宽
#define TIME_CHIRP ((double)NUM_SAMPLE / ADC_SAMPLE_RATE)                                                      ///< 等效Chirp时长

#define NUM_CHANNEL (NUM_TX_ANTENNA * NUM_RX_ANTENNA)

#define TIME_CHRIP_TOTAL_EXPECTED ((double)WAVE_LENGTH / (4.0 * MAX_SPEED_RANGE))                                      ///< 期望的Chirp总时长
#define TIME_COHERENT_CHIRPS ((double)(FMCW_RISE_STEP_NUM + COHERENT_CHIRP_GAP) * FMCW_RISE_STEP * NUM_COHERENT_CHIRP) ///< 相干Chirp总时长
#define TIME_SUBFRAME_INTERVAL_US ((unsigned long)((TIME_CHRIP_TOTAL_EXPECTED - TIME_COHERENT_CHIRPS) * 1e6))          ///< SUBFRAME间隔
#define TIME_CHRIP_TOTAL (TIME_COHERENT_CHIRPS + TIME_SUBFRAME_INTERVAL_US / 1e6)                                      ///< Chirp总时长
#define TIME_CHRIPGAP (TIME_CHRIP_TOTAL - TIME_CHIRP)                                                                  ///< 等效帧间隔

int main()
{
    double range_bin_size = 149896229.0 / BANDWIDTH; // Range Bin大小
    std::cout << BANDWIDTH << std::endl;
    std::cout << range_bin_size << std::endl;
    std::cout << range_bin_size * 32 << std::endl;
    std::cout << TIME_SUBFRAME_INTERVAL_US << std::endl;
    std::cout << TIME_CHIRP << std::endl;
    std::cout << TIME_CHRIP_TOTAL_EXPECTED << std::endl;
    std::cout << TIME_COHERENT_CHIRPS << std::endl;
    std::cout << TIME_CHRIP_TOTAL << std::endl;
    std::cout << TIME_CHRIPGAP << std::endl;
    // std::cout << "***************************************************\n"

    //           << "            ccc                   ssss         !!  \n"
    //           << "           C   C                S      S       !!  \n"
    //           << "            ccc                   ssss         !!  \n"
    //           << "            ccc                   ssss         !!  \n"
    //           << "            ccc                   ssss         !!  \n"
    //           << "            ccc                   ssss         !!  \n"
    //           << "            ccc                   ssss         !!  \n"
    //           << "            ccc                   ssss         !!  \n"
    //           << "            ccc                   ssss         !!  \n"
    //           << "            ccc                   ssss         !!  \n"

    //           << "***************************************************\n"
    //           << std::endl;
    // std::cout << "c:\\files\\" << std::endl;
    // std::cout << R"(c:\files\)" << std::endl;
    // // std::endl;   == \n
    // double weight = 79.8;
    // std::cout << weight << std::endl;
    // std::cout.setf(std::ios::fixed);
    // std::cout.setf(std::ios::showpoint);
    // std::cout.precision(2);
    // std::cout << weight << std::endl;
    // std::cout.precision(3);
    // std::cout << weight << std::endl;
    // int a = 9, b = 2;
    // double c = static_cast<double>(a) / b;
    // double d = double(a) / b; // 古老的强制类型转换
    // std::cout << c << std::endl;
    // std::cout << c << std::endl;
    // std::cout.unsetf(std::ios::fixed);
    // std::cout << c << std::endl;

    return 0;
}
// 编程提示：使用 \n和endl终止每一个程序
//  添加换行符的作用是，在某些编译器中不输出程序的最后一行，或者有些编译器在运行下一个程序时，会将自己的第一行输出与上一行输出混在一起
