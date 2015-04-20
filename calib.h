//calib.h
//Our thermometer does NOT require this file. Our code uses a nonlinear equation that we obtained using the Voltage,
//Temperature, and Resistance equations on therm12.xls. However, we will put some calibration information here.

//Calibration data
//True val: 24.05, measured: 24.01
//True val: 24.06, measured: 24.01
//True val: 24.05, measured: 24.03
//True val: 24.09, measured: 24.07
//True val: 24.04, measured: 24.05
//So, to adjust for calibration, we would get the temp. value and add 0.02


//From therm12.xls
uint16_t const ADCdata[53]={0,157,195,233,272,313,355,398,442,488,535,
     583,633,684,737,791,847,905,964,1024,1087,
     1151,1217,1285,1355,1427,1501,1577,1655,1735,1817,
     1901,1988,2077,2168,2262,2358,2456,2557,2660,2766,
     2875,2985,3099,3215,3334,3455,3578,3705,3834,3965,4095,4096};

uint16_t const Tdata[53]={4000,4000,3920,3840,3760,3680,3600,3520,3440,3360,3280,
     3200,3120,3040,2960,2880,2800,2720,2640,2560,2480,
     2400,2320,2240,2160,2080,2000,1920,1840,1760,1680,
     1600,1520,1440,1360,1280,1200,1120,1040,960,880,
     800,720,640,560,480,400,320,240,160,80,0,0};

uint16_t const Rdata[53]={570,570,587,604,622,641,660,680,701,722,744,
     767,791,815,841,868,895,924,953,984,1016,
     1049,1083,1119,1156,1194,1234,1276,1319,1364,1410,
     1459,1509,1562,1616,1673,1733,1794,1858,1925,1995,
     2068,2144,2222,2305,2391,2480,2574,2672,2774,2880,2991,2991};
