#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <string.h>
#include <math.h>
#define in_nums 20
//向量的维度
#define out_nums 1
//0,1判断是不是有病毒
#define hidden1_nums 30
#define hidden2_nums 10
float x_layer[in_nums];
float weight1[hidden1_nums][in_nums]=
      { {-7.4877e-02,  1.4307e-03, -1.1206e-01, -1.2064e-01, -4.2227e-01,
          2.4664e-01,  1.6300e-02, -2.3685e-01,  9.2414e-02, -2.3079e-01,
         -1.2147e-01,  1.0425e-01,  1.0307e-01, -2.0979e-02, -2.8557e-01,
         -2.6860e-01,  1.3189e-01,  8.2987e-02,  1.7928e-01, -2.2669e-01},
       {-2.7403e-01,  9.5937e-02,  1.3691e-02, -1.2856e-02, -4.8309e-02,
          6.1570e-01,  1.0344e-02,  3.2837e-01,  3.9554e-01, -6.4150e-03,
          1.0692e-01, -2.0694e-01,  1.1691e-01, -2.8641e-01, -9.9037e-03,
          6.5866e-02, -1.0803e-01,  7.3955e-02,  6.4183e-03,  2.2589e-02},
       {-8.4078e-02, -3.9805e-02, -2.2853e-01,  1.8518e-01, -3.8643e-01,
          2.4378e-01, -6.9389e-02, -6.7475e-01, -1.9167e-01,  1.7560e-01,
          2.7176e-01, -4.6170e-03, -2.6916e-01,  8.1653e-02, -1.1358e-01,
          9.8995e-02, -1.5426e-01, -3.7516e-02, -2.1044e-01,  6.8213e-04},
       {-5.9290e-02,  5.7679e-02, -9.5549e-02, -1.0563e-01, -1.6792e-02,
         -4.1196e-01, -2.4803e-01, -1.9040e-01, -7.7655e-02, -8.1214e-02,
         -3.3394e-01, -3.1629e-02,  1.0866e-01, -1.7249e-01, -2.0519e-01,
          6.4577e-02, -1.7347e-01, -2.3102e-01, -1.6687e-01, -3.2630e-01},
       { 1.1966e-01, -6.3841e-02,  5.8378e-03,  1.4981e-01,  4.2642e-02,
         -5.8194e-02,  1.4847e-01, -1.3523e-01,  5.7686e-03,  2.1684e-01,
         -5.6076e-02,  1.8932e-02,  1.0586e-01, -1.3154e-01, -2.5578e-01,
          3.0766e-02, -1.5458e-01, -9.6585e-03,  1.4447e-01,  5.8101e-02},
       { 7.9350e-02, -1.6029e-02, -6.9842e-02,  1.1140e-01, -7.4724e-02,
         -1.7177e-01, -4.9636e-02, -4.9516e-01, -3.4099e-01,  1.0767e-01,
          6.3994e-02,  3.0464e-02, -3.2583e-01, -2.4062e-02, -2.4918e-01,
          7.9310e-02,  4.6440e-02,  7.3546e-02,  6.1994e-02,  7.8897e-03},
       { 4.5028e-03, -2.3686e-01, -3.6416e-01, -1.4495e-01,  6.7411e-02,
          4.4230e-02,  9.3338e-02, -4.4234e-01, -2.6499e-01, -1.8191e-01,
         -3.7628e-01, -1.6695e-01, -4.6330e-02, -3.9885e-02, -3.9377e-01,
         -5.9915e-01, -5.8089e-01,  1.1272e-01,  1.4691e-01, -1.5562e-01},
       { 3.2794e-02,  2.3246e-03, -1.6208e-01,  1.2766e-02, -2.1803e-01,
          4.4851e-03, -2.4047e-01,  7.7719e-02, -1.0587e-01,  6.0468e-03,
          1.2044e-01,  4.8844e-02, -1.5856e-01, -3.2520e-01,  8.7703e-03,
          9.4439e-02,  8.9249e-02, -1.1100e-01, -2.5985e-02,  1.4703e-01},
       {-2.0252e-01, -2.4132e-01,  1.2424e-01, -2.0145e-01, -4.1049e-01,
         -2.2475e-01,  4.4021e-03,  4.8089e-03, -1.3897e-01, -1.1230e-01,
          1.1491e-01, -1.8804e-01, -4.3412e-01,  8.8501e-02, -1.4128e-01,
          5.1185e-02, -7.5408e-01,  1.6283e-01, -2.1403e-01, -1.6612e-01},
       { 1.7590e-02,  9.3937e-02, -2.2368e-01,  2.2674e-02,  1.3819e-01,
         -2.4202e-02, -1.5754e-01, -4.9360e-02, -1.4955e-01, -1.4343e-01,
          6.0851e-02,  6.1335e-02, -2.2991e-01,  6.8746e-02, -7.0858e-02,
         -2.3007e-02,  2.7219e-01, -1.8214e-02,  4.2089e-02,  1.3450e-01},
       {-2.3624e-01, -7.0092e-01, -2.3326e-01, -4.0922e-01, -4.1808e-01,
         -9.9230e-02,  1.2727e-01,  8.3283e-02, -3.1623e-01, -2.3075e-01,
          2.8693e-02, -1.7592e-01,  1.3417e-02, -2.8553e-02, -2.7670e-01,
         -6.3087e-02,  4.7888e-02,  8.4907e-02,  1.1268e-01, -2.1589e-02},
       { 8.0434e-02, -4.4155e-04, -3.1712e-01,  4.7527e-01,  1.3954e-01,
         -2.9152e-02,  4.8558e-01,  6.0660e-01,  2.1567e-01,  1.3358e-01,
          9.8471e-02, -2.2365e-01, -2.5853e-02,  2.4563e-01,  2.0529e-01,
          1.9042e-01, -1.6164e-01, -2.6575e-02, -2.4745e-01, -8.0571e-02},
       { 1.6589e-01, -5.3860e-02,  1.9181e-02, -1.0304e-01, -1.1036e-01,
         -1.9054e-01, -2.7307e-01, -1.0683e-01, -1.6555e-01, -1.5173e-01,
         -5.6875e-02, -2.0676e-02, -2.1829e-01,  5.2607e-02, -5.8921e-02,
         -2.0419e-01, -2.3855e-01, -1.3634e-02,  1.2263e-01,  6.5403e-02},
       {-6.3152e-02,  2.8613e-02, -3.2348e-01,  9.7009e-02, -1.2749e-01,
          5.1200e-03, -3.6028e-02, -6.7553e-02,  1.4342e-01,  1.3891e-01,
         -6.2228e-02,  2.6805e-02, -1.3970e-01,  1.0672e-01, -1.0270e-02,
          2.8741e-03,  1.4720e-01,  7.3309e-02, -1.8069e-01, -1.5521e-03},
       { 4.0876e-02, -3.2896e-04,  6.9772e-02, -3.0877e-01,  5.3606e-02,
         -1.7184e-02,  1.0697e-01, -2.4377e-01, -2.4509e-01,  1.4101e-01,
         -3.4631e-01,  4.3999e-02,  1.8615e-01, -3.6757e-01,  1.8322e-02,
         -4.2728e-01,  7.4050e-02, -1.2517e-01, -7.0241e-03, -1.9750e-01},
       { 9.4659e-02,  2.5714e-02,  1.3646e-01,  7.0851e-02, -3.1647e-01,
          4.0135e-02, -4.1307e-01,  2.5073e-01, -3.3705e-01,  4.3014e-02,
         -1.4956e-01,  9.3372e-02, -1.4829e-01,  1.7313e-02, -5.1243e-01,
          1.6039e-01, -4.6814e-01, -2.0054e-02, -5.8223e-02, -4.0280e-01},
       { 9.1522e-02,  1.0440e-01, -1.3380e-02, -2.9144e-02, -2.2005e-01,
         -1.2454e-01, -2.7863e-01,  9.4413e-03, -2.5917e-01,  7.5227e-02,
          1.0083e-02, -3.8086e-02,  6.0923e-02, -3.0573e-01, -1.6582e-01,
         -2.1524e-01, -9.5994e-02,  1.5795e-02,  1.7471e-01,  3.5047e-02},
       { 1.1618e-02, -2.9633e-02, -1.7355e-01,  4.5027e-01,  1.9998e-02,
         -3.6748e-02, -4.1063e-01, -3.2108e-01, -1.8723e-01,  1.0672e-01,
          2.2884e-01, -2.4908e-01, -6.6027e-01,  1.7920e-01, -2.1224e-01,
          9.2504e-02, -3.9765e-01, -3.2124e-01,  5.8279e-02, -1.2753e-01},
       { 3.2709e-02, -3.4698e-02, -1.2700e-01,  5.0608e-01,  1.9262e-01,
         -4.7413e-02,  1.0469e-01,  5.2128e-01,  6.2606e-02, -1.0112e-01,
          1.0020e-01, -7.6193e-02, -1.5887e-01, -1.7019e-01,  9.1668e-02,
          1.4611e-01,  1.6220e-02, -8.4275e-02,  5.1084e-02,  2.3745e-04},
       {-2.1037e-01,  1.6321e-03,  5.3881e-03,  5.3356e-02, -1.3954e-01,
         -1.0430e-01, -5.3247e-03, -1.1702e-03,  5.0656e-02, -3.1731e-01,
         -4.1890e-01,  1.9928e-01,  7.2724e-02, -4.4659e-02, -1.1698e-01,
         -2.8646e-01, -3.5381e-01, -1.2319e-01,  1.1284e-01, -5.3149e-02},
       {-2.5146e-01,  3.8679e-02, -5.3189e-01, -4.8457e-02, -1.5915e-01,
          1.1541e-01, -2.6526e-01,  1.4796e-01, -3.1253e-01,  1.3346e-01,
          9.9582e-02,  2.0496e-02, -5.5536e-02, -2.2828e-01, -2.2144e-01,
         -2.7287e-01, -1.4690e-02,  5.9568e-02,  1.3377e-01, -3.5315e-02},
       { 8.2302e-04,  6.8778e-02, -5.0025e-03, -1.1700e-01,  1.5359e-02,
         -1.5051e-01, -9.9336e-02, -3.7444e-01, -5.1123e-02,  1.3331e-01,
          8.9320e-02, -2.2312e-01,  1.0913e-01, -3.4644e-02, -2.1999e-01,
          2.7455e-02, -2.0188e-01, -1.1659e-01,  2.6319e-02, -3.3369e-01},
       { 6.5528e-02, -1.9431e-02,  8.0403e-02, -8.8589e-02, -5.5542e-02,
          8.9495e-03, -2.4808e-03,  1.3491e-01,  1.1580e-01,  2.8225e-01,
          1.7363e-01, -4.8752e-02,  4.3183e-02,  1.9349e-01, -6.8219e-02,
          1.1702e-02, -7.6810e-02, -7.9034e-02, -4.0351e-02,  1.4931e-01},
       {-2.2380e-01,  1.7727e-02, -3.6266e-01,  1.6092e-02, -6.8886e-02,
          1.9311e-01,  1.5611e-01,  3.0557e-03,  2.6092e-01,  1.2054e-01,
         -8.2784e-02,  7.2833e-03,  9.3889e-02,  4.3398e-02,  8.0063e-02,
         -1.3562e-01,  4.0923e-02, -4.4308e-02, -4.6114e-03,  5.3957e-03},
       {-1.9557e-01, -1.7450e-01, -1.4824e-01,  1.3242e-02,  2.4690e-01,
          1.4700e-01, -1.0337e-01, -3.4632e-02, -1.5580e-01,  4.6988e-02,
          2.7054e-01, -1.0060e-02,  8.1047e-02, -1.4470e-01,  3.9628e-02,
         -1.3520e-01, -1.3243e-01,  2.5219e-02,  1.4213e-01,  7.6959e-03},
       {-1.0800e-01, -1.3645e-01,  1.4732e-01, -1.7770e-02, -9.5882e-02,
          1.1998e-02, -1.8924e-01, -1.4847e-02,  1.9107e-01, -2.8086e-01,
          4.0953e-02,  9.5663e-02, -2.3382e-03, -7.2914e-01, -2.2850e-01,
          3.6516e-02, -2.8398e-01, -1.2554e-01,  9.1911e-02,  7.4298e-02},
       {-1.0564e-01,  1.0133e-01, -4.7492e-03,  4.2951e-01,  2.4457e-01,
          1.7960e-01,  4.3628e-03,  5.1850e-01,  1.8712e-01, -1.4580e-01,
          1.0602e-01, -1.5813e-01,  6.8243e-02, -4.6412e-02, -6.5511e-02,
          7.7638e-02, -1.1472e-01,  3.9379e-02,  6.2703e-03,  1.1869e-02},
       {-1.5091e-01, -9.4457e-02,  6.6221e-02, -5.7251e-02, -3.4695e-01,
         -1.9135e-01, -7.8419e-02,  4.9459e-02, -7.1616e-01, -4.2556e-01,
          2.2530e-01, -4.3560e-01, -3.5442e-01, -3.2386e-03, -1.4967e-01,
          1.2678e-01, -3.9930e-01, -2.2233e-01, -3.1707e-02, -1.0821e-01},
       {-3.5793e-02,  1.3860e-01, -9.9321e-02,  1.9367e-01,  8.8863e-02,
          6.8269e-02,  1.7027e-03,  5.4017e-01,  5.5111e-01,  1.2451e-01,
          2.4577e-01, -1.8983e-01, -5.0998e-02,  2.1514e-02,  2.7982e-01,
          3.0862e-02, -1.2243e-01, -1.0590e-01,  7.7610e-02,  3.0928e-02},
       { 3.0196e-02, -2.1801e-01,  1.5535e-01, -3.1185e-01, -6.9699e-02,
          2.3174e-01, -8.1395e-02, -3.8669e-02, -2.7230e-01, -2.2575e-01,
         -3.2916e-01, -3.7689e-01, -3.3084e-01, -1.2826e-01,  7.5505e-02,
         -3.5243e-02,  3.3745e-01, -3.0868e-01, -3.3938e-01, -2.1064e-01}};
float h1_layer[hidden1_nums];
float weight2[hidden2_nums][hidden1_nums]={ { 0.0738, -0.0320, -0.0816,  0.1032,  0.0255, -0.0085,  0.1069,  0.0748,
          0.0373, -0.0523, -0.1169,  0.0923,  0.0887, -0.0038, -0.0985, -0.0683,
         -0.0419, -0.0121,  0.1047, -0.0025, -0.0992, -0.0151, -0.0644,  0.1303,
         -0.0976,  0.1726,  0.1340, -0.0255, -0.0461,  0.0441},
       {-0.2009, -0.0035, -0.4994,  0.0726, -0.0656,  0.1875, -1.4849,  0.2151,
         -0.1080, -1.3808,  0.0824, -1.2347,  0.1185,  0.0945, -0.1330,  0.1104,
          0.0042, -0.9512,  0.3269,  0.0817, -1.2274,  0.0464,  0.0233, -0.4175,
          0.3831, -0.0661, -0.0908, -0.0200, -1.7779,  0.0242},
       {-0.1151,  0.0865, -0.0930, -0.4817, -0.0172,  0.1128,  0.1487,  0.2496,
          0.3338,  0.0460,  0.0172,  0.0944, -0.1427, -0.0426, -0.2836, -0.1293,
         -0.0372, -0.0415,  0.3364,  0.1933, -0.0703, -0.0924, -0.0818,  0.1246,
          0.0914, -0.3537, -0.1765, -1.5836,  0.0327, -1.6020},
       { 0.0317,  0.1132,  0.2786,  0.1533,  0.0164, -0.0143,  0.2725,  0.2988,
         -0.0740, -0.0747, -0.1276,  0.0471,  0.0894,  0.2486, -0.8571, -0.1388,
         -0.1255,  0.0287,  0.3171,  0.2580,  0.0311, -0.0039, -0.2073,  0.0965,
         -0.1124, -0.4502,  0.0343, -1.2690, -0.1081, -0.7863},
       { 0.1011, -0.1077,  0.1172,  0.0859, -0.2143,  0.0345,  0.1744,  0.0051,
         -0.0607, -0.0969, -0.0084,  0.1409, -0.0831,  0.0254, -0.0285,  0.1005,
          0.0715,  0.1468,  0.1184,  0.1637, -0.1600,  0.1584, -0.0782,  0.0188,
         -0.0024, -0.3181,  0.1054, -0.1439, -0.0757, -0.2657},
       { 0.0361, -0.2078, -0.0932,  0.4969, -0.1204,  0.1678, -0.8261,  0.3051,
         -0.0087, -0.1869, -0.4441, -0.1360,  0.0625, -0.7062,  0.0310, -0.0976,
         -0.1003, -0.6525,  0.2930,  0.1217,  0.0353,  0.1524,  0.0388, -0.8732,
         -0.0418, -0.0261, -0.4395, -0.0900, -1.2975,  0.2141},
       { 0.0966, -0.0786, -0.0917, -0.1436,  0.0799,  0.0663, -0.0797, -0.0944,
         -0.1555,  0.0856,  0.1326, -0.0170,  0.0617,  0.1084, -0.0974,  0.0041,
         -0.0960, -0.0838,  0.1163,  0.0261, -0.0691,  0.0101,  0.0674,  0.1278,
         -0.1506,  0.0970,  0.1339,  0.1166, -0.1085,  0.0660},
       {-0.0904, -0.0337, -0.7247,  0.0655, -0.2055,  0.0687, -0.0598,  0.0555,
          0.1734, -0.0858, -0.1099,  0.0962,  0.0614, -0.0788, -0.0115, -0.0152,
          0.1809, -0.2292,  0.1091,  0.0811,  0.0026, -0.0393,  0.0596, -0.1824,
          0.2169, -0.1174,  0.1246, -0.1036,  0.0140, -0.0444},
       { 0.0983, -0.1748, -0.1070,  0.5229,  0.1481,  0.1147,  0.0911,  0.1792,
          0.0229, -0.0319,  0.0181, -0.1052, -0.1342, -0.0786,  0.1638, -0.0819,
         -0.0650, -0.0142, -0.1431, -0.0396, -0.2981,  0.0245, -0.1392,  0.0711,
         -0.2268, -0.0811, -0.1249,  0.0536, -0.0676,  0.1208},
       {-0.0797,  0.1291, -0.2450, -0.0030, -0.0994,  0.0998, -0.2361,  0.1178,
          0.0775,  0.0162,  0.0394, -0.1011,  0.1005,  0.1751,  0.1194, -0.0112,
          0.1272, -0.1688,  0.0182,  0.0725,  0.0281,  0.0410, -0.0830, -0.1667,
          0.0610, -0.1326, -0.1202, -0.7486, -0.2008,  0.1381}};
float h2_layer[hidden2_nums];
float weight3[hidden2_nums][out_nums]=
{-0.1506, -0.1815,  0.0737,  0.0833, -0.0597, -0.1124,  0.1351,  0.0164,
         -0.1404, -0.0766};
float y_layer[out_nums];
float gamma_h1[hidden1_nums]={-0.0936,  0.4318, -0.0739, -0.0566, -0.2182,  0.3181, -0.0720,  0.9321,
        -0.1017,  0.3753,  0.1788,  2.2384,  0.0142,  2.5291,  0.1210, -1.4461,
        -0.4740,  0.2476,  3.6999,  2.8619,  0.3916,  0.0893,  0.1207,  1.2244,
        -0.7568, -0.5845,  0.4690, -0.0204, -0.0053,  0.2704};//隐藏层的偏执量
float gamma_h2[hidden2_nums]={-0.4123,  1.7688,  1.2740,  0.7453, -0.3646,  1.6760,  0.4329,  1.4412,
        -0.1291,  0.0317};
float ceita_y[out_nums]={0.3974};
float  relu(float x)
{
    return x>=0?x:0;
}


  
       
/*void test()
{
    hashtable ht;
    init(&ht,10000);
    insert(&ht,20,10);
    insert(&ht,30,10);
    insert(&ht,25,11);
    insert(&ht,26,13);
    insert(&ht,26,14);
    if(!findhs(&ht,27))
    insert(&ht,27,0);
    addone(&ht,27);
    addone(&ht,26);
    insert(&ht,2,10);
    hashnode* a=findhs(&ht,27);
    printf("state:%d,key;%d,value:%d\n", a->state, a->key, a->value);
    removehs(&ht,2);
    showinfo(&ht);
    insert(&ht,6,13);
    insert(&ht,2,12);
    showinfo(&ht);
}*/

int main(int argc, char const *argv[])

{   hashtable ht;
    init(&ht,300000);
  
    char buf[1];

    FILE *fp = NULL;
    int cnt = 0;
    fp = fopen("./virus/Trojan-Downloader.Win32.Zlob.rhv", "rb");
    char lastchar;
    char windows[2];
    if(!fp){
        fputs("open failed!", stderr);
        return 1;
    }
    
    fread(buf, sizeof(char), 1, fp);
    lastchar = buf[0];
    int num=0;
    while((cnt = fread(buf, sizeof(char), 1, fp))){
          ++num;
            windows[0]=lastchar;
            windows[1]=buf[0];
        
         int left=(unsigned char)windows[0];
         int right=(unsigned char)windows[1];
         int tmp=left*256+right;
         if(!findhs(&ht,tmp))
             insert(&ht,tmp,1);
         else
            addone(&ht,tmp);
        lastchar = buf[0];
        
    }
    
    showinfo(&ht);
    printf("%d\n",num);
    int vec[20]={12336,4626,18504,10504,47205,53199,10557,11304,14888,55962,20051,33984,65313,60397,9766,8486,9892,60927,65515,15615};
    //int input[20];
    for(int i=0;i<20;++i)
    { if(!findhs(&ht,vec[i]))
       x_layer[i]=0;
       else
       x_layer[i]=(float)findhs(&ht,vec[i])->value;
    
    }
    printf("%2f",1.55e-1);
    for(int i=0;i<20;++i)
    { 
    printf("%f\n",x_layer[i]);
    }
    printf("success");
        for(int j=0;j<hidden1_nums;++j)
     {
        float sum=0;
        for(int i=0;i<in_nums;++i)
        {
        sum+=weight1[j][i]*x_layer[i];
        }
        h1_layer[j]=relu(sum+gamma_h1[j]);
     }
     
     for(int j=0;j<hidden2_nums;++j)
     {
        float sum=0;
        for(int i=0;i<hidden1_nums;++i)
        {
        sum+=weight2[j][i]*h1_layer[i];
        }
        h2_layer[j]=relu(sum+gamma_h2[j]);
     }
     for(int j=0;j<out_nums;++j)
     {
        float sum=0;
        for(int i=0;i<hidden2_nums;++i)
        {
        sum+=weight3[j][i]*h2_layer[i];
        }
        
        y_layer[j]=relu(sum+ceita_y[j]);
     }
     printf("%3f",y_layer[0]);
    return 0; 
}
