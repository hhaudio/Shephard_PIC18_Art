/* 
 * File:   CosineTables.h
 * Author: emmettpalaima
 *
 * Created on April 16, 2020, 10:09 PM
 */

#ifndef COSINETABLES_H
#define	COSINETABLES_H

const uint16_t cosTab[1024] = {
4095, 4094, 4094, 4094, 4094, 4094, 4093, 4093, 4092, 4091, 4091, 4090, 4089, 4088, 4087, 4086, 
4085, 4083, 4082, 4081, 4079, 4078, 4076, 4074, 4072, 4070, 4068, 4066, 4064, 4062, 4060, 4058, 
4055, 4053, 4050, 4047, 4045, 4042, 4039, 4036, 4033, 4030, 4027, 4024, 4020, 4017, 4013, 4010, 
4006, 4003, 3999, 3995, 3991, 3987, 3983, 3979, 3975, 3971, 3966, 3962, 3957, 3953, 3948, 3943, 
3939, 3934, 3929, 3924, 3919, 3914, 3909, 3903, 3898, 3893, 3887, 3881, 3876, 3870, 3864, 3859, 
3853, 3847, 3841, 3835, 3829, 3822, 3816, 3810, 3803, 3797, 3790, 3784, 3777, 3770, 3763, 3756, 
3749, 3742, 3735, 3728, 3721, 3714, 3706, 3699, 3692, 3684, 3676, 3669, 3661, 3653, 3646, 3638, 
3630, 3622, 3614, 3606, 3597, 3589, 3581, 3573, 3564, 3556, 3547, 3539, 3530, 3521, 3512, 3504, 
3495, 3486, 3477, 3468, 3459, 3450, 3441, 3431, 3422, 3413, 3403, 3394, 3384, 3375, 3365, 3356, 
3346, 3336, 3326, 3317, 3307, 3297, 3287, 3277, 3267, 3257, 3246, 3236, 3226, 3216, 3205, 3195, 
3185, 3174, 3164, 3153, 3142, 3132, 3121, 3110, 3100, 3089, 3078, 3067, 3056, 3045, 3034, 3023, 
3012, 3001, 2990, 2979, 2968, 2956, 2945, 2934, 2922, 2911, 2900, 2888, 2877, 2865, 2854, 2842, 
2831, 2819, 2807, 2796, 2784, 2772, 2760, 2749, 2737, 2725, 2713, 2701, 2689, 2677, 2665, 2653, 
2641, 2629, 2617, 2605, 2593, 2581, 2569, 2557, 2545, 2532, 2520, 2508, 2496, 2483, 2471, 2459, 
2446, 2434, 2422, 2409, 2397, 2385, 2372, 2360, 2347, 2335, 2323, 2310, 2298, 2285, 2273, 2260, 
2248, 2235, 2223, 2210, 2198, 2185, 2173, 2160, 2147, 2135, 2122, 2110, 2097, 2085, 2072, 2060, 
2047, 2034, 2022, 2009, 1997, 1984, 1972, 1959, 1947, 1934, 1921, 1909, 1896, 1884, 1871, 1859, 
1846, 1834, 1821, 1809, 1796, 1784, 1771, 1759, 1747, 1734, 1722, 1709, 1697, 1685, 1672, 1660, 
1648, 1635, 1623, 1611, 1598, 1586, 1574, 1562, 1549, 1537, 1525, 1513, 1501, 1489, 1477, 1465, 
1453, 1441, 1429, 1417, 1405, 1393, 1381, 1369, 1357, 1345, 1334, 1322, 1310, 1298, 1287, 1275, 
1263, 1252, 1240, 1229, 1217, 1206, 1194, 1183, 1172, 1160, 1149, 1138, 1126, 1115, 1104, 1093, 
1082, 1071, 1060, 1049, 1038, 1027, 1016, 1005, 994, 984, 973, 962, 952, 941, 930, 920, 
909, 899, 889, 878, 868, 858, 848, 837, 827, 817, 807, 797, 787, 777, 768, 758, 
748, 738, 729, 719, 710, 700, 691, 681, 672, 663, 653, 644, 635, 626, 617, 608, 
599, 590, 582, 573, 564, 555, 547, 538, 530, 521, 513, 505, 497, 488, 480, 472, 
464, 456, 448, 441, 433, 425, 418, 410, 402, 395, 388, 380, 373, 366, 359, 352, 
345, 338, 331, 324, 317, 310, 304, 297, 291, 284, 278, 272, 265, 259, 253, 247, 
241, 235, 230, 224, 218, 213, 207, 201, 196, 191, 185, 180, 175, 170, 165, 160, 
155, 151, 146, 141, 137, 132, 128, 123, 119, 115, 111, 107, 103, 99, 95, 91, 
88, 84, 81, 77, 74, 70, 67, 64, 61, 58, 55, 52, 49, 47, 44, 41, 
39, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 15, 13, 12, 11, 
9, 8, 7, 6, 5, 4, 3, 3, 2, 1, 1, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 
9, 11, 12, 13, 15, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 
39, 41, 44, 47, 49, 52, 55, 58, 61, 64, 67, 70, 74, 77, 81, 84, 
88, 91, 95, 99, 103, 107, 111, 115, 119, 123, 128, 132, 137, 141, 146, 151, 
155, 160, 165, 170, 175, 180, 185, 191, 196, 201, 207, 213, 218, 224, 230, 235, 
241, 247, 253, 259, 265, 272, 278, 284, 291, 297, 304, 310, 317, 324, 331, 338, 
345, 352, 359, 366, 373, 380, 388, 395, 402, 410, 418, 425, 433, 441, 448, 456, 
464, 472, 480, 488, 497, 505, 513, 521, 530, 538, 547, 555, 564, 573, 582, 590, 
599, 608, 617, 626, 635, 644, 653, 663, 672, 681, 691, 700, 710, 719, 729, 738, 
748, 758, 768, 777, 787, 797, 807, 817, 827, 837, 848, 858, 868, 878, 889, 899, 
909, 920, 930, 941, 952, 962, 973, 984, 994, 1005, 1016, 1027, 1038, 1049, 1060, 1071, 
1082, 1093, 1104, 1115, 1126, 1138, 1149, 1160, 1172, 1183, 1194, 1206, 1217, 1229, 1240, 1252, 
1263, 1275, 1287, 1298, 1310, 1322, 1334, 1345, 1357, 1369, 1381, 1393, 1405, 1417, 1429, 1441, 
1453, 1465, 1477, 1489, 1501, 1513, 1525, 1537, 1549, 1562, 1574, 1586, 1598, 1611, 1623, 1635, 
1648, 1660, 1672, 1685, 1697, 1709, 1722, 1734, 1747, 1759, 1771, 1784, 1796, 1809, 1821, 1834, 
1846, 1859, 1871, 1884, 1896, 1909, 1921, 1934, 1947, 1959, 1972, 1984, 1997, 2009, 2022, 2034, 
2047, 2060, 2072, 2085, 2097, 2110, 2122, 2135, 2147, 2160, 2173, 2185, 2198, 2210, 2223, 2235, 
2248, 2260, 2273, 2285, 2298, 2310, 2323, 2335, 2347, 2360, 2372, 2385, 2397, 2409, 2422, 2434, 
2446, 2459, 2471, 2483, 2496, 2508, 2520, 2532, 2545, 2557, 2569, 2581, 2593, 2605, 2617, 2629, 
2641, 2653, 2665, 2677, 2689, 2701, 2713, 2725, 2737, 2749, 2760, 2772, 2784, 2796, 2807, 2819, 
2831, 2842, 2854, 2865, 2877, 2888, 2900, 2911, 2922, 2934, 2945, 2956, 2968, 2979, 2990, 3001, 
3012, 3023, 3034, 3045, 3056, 3067, 3078, 3089, 3100, 3110, 3121, 3132, 3142, 3153, 3164, 3174, 
3185, 3195, 3205, 3216, 3226, 3236, 3246, 3257, 3267, 3277, 3287, 3297, 3307, 3317, 3326, 3336, 
3346, 3356, 3365, 3375, 3384, 3394, 3403, 3413, 3422, 3431, 3441, 3450, 3459, 3468, 3477, 3486, 
3495, 3504, 3512, 3521, 3530, 3539, 3547, 3556, 3564, 3573, 3581, 3589, 3597, 3606, 3614, 3622, 
3630, 3638, 3646, 3653, 3661, 3669, 3676, 3684, 3692, 3699, 3706, 3714, 3721, 3728, 3735, 3742, 
3749, 3756, 3763, 3770, 3777, 3784, 3790, 3797, 3803, 3810, 3816, 3822, 3829, 3835, 3841, 3847, 
3853, 3859, 3864, 3870, 3876, 3881, 3887, 3893, 3898, 3903, 3909, 3914, 3919, 3924, 3929, 3934, 
3939, 3943, 3948, 3953, 3957, 3962, 3966, 3971, 3975, 3979, 3983, 3987, 3991, 3995, 3999, 4003, 
4006, 4010, 4013, 4017, 4020, 4024, 4027, 4030, 4033, 4036, 4039, 4042, 4045, 4047, 4050, 4053, 
4055, 4058, 4060, 4062, 4064, 4066, 4068, 4070, 4072, 4074, 4076, 4078, 4079, 4081, 4082, 4083, 
4085, 4086, 4087, 4088, 4089, 4090, 4091, 4091, 4092, 4093, 4093, 4094, 4094, 4094, 4094, 4094};


#endif	/* COSINETABLES_H */

