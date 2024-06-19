#include "encrypt.h"


//Public Key

// Term h[N3] = {{208.0, 137.0}, {-147.0, -194.0}, {27.0, 207.0}, {-72.0, -123.0}, {-81.0, -5.0}, {-51.0, -60.0}, {4.0, 144.0}, {-24.0, 149.0}, {71.0, -139.0}, {-78.0, -91.0}, {55.0, 194.0}, {-138.0, -169.0}, {201.0, 156.0}, {86.0, -66.0}, {-187.0, -73.0}, {-151.0, 34.0}, {251.0, 114.0}, {45.0, -114.0}, {8.0, -193.0}, {161.0, -30.0}, {-124.0, -26.0}, {80.0, 108.0}, {-75.0, -128.0}, {-27.0, -39.0}, {-123.0, -46.0}, {-121.0, 125.0}, {-151.0, -139.0}, {-59.0, -175.0}, {-60.0, -99.0}, {54.0, -143.0}, {147.0, 64.0}, {-12.0, -201.0}, {-102.0, 35.0}, {10.0, -72.0}, {168.0, 210.0}, {-6.0, 43.0}, {74.0, 161.0}, {-127.0, 115.0}, {-57.0, -206.0}, {104.0, 41.0}, {-41.0, -81.0}, {-154.0, -60.0}, {-8.0, 113.0}, {162.0, 159.0}, {-223.0, -104.0}, {-190.0, -19.0}, {60.0, -166.0}, {-27.0, -138.0}, {-141.0, -121.0}, {-106.0, 66.0}, {98.0, -123.0}, {153.0, -33.0}, {204.0, 179.0}, {88.0, -65.0}, {42.0, 110.0}, {254.0, 127.0}, {-180.0, -24.0}, {158.0, 70.0}, {159.0, -11.0}, {-122.0, -24.0}, {-193.0, -149.0}, {79.0, -56.0}, {103.0, -127.0}, {137.0, -126.0}, {192.0, 137.0}, {70.0, 16.0}, {-47.0, 39.0}, {-123.0, -11.0}, {-156.0, -40.0}, {223.0, 93.0}, {-102.0, 3.0}, {11.0, 37.0}, {-27.0, -171.0}, {-36.0, -55.0}, {119.0, -30.0}, {-136.0, 99.0}, {-35.0, -151.0}, {-194.0, 6.0}, {-186.0, 3.0}, {111.0, -141.0}, {56.0, 164.0}, {194.0, 126.0}, {-117.0, 119.0}, {-150.0, -42.0}, {-229.0, -130.0}, {-218.0, -158.0}, {164.0, 181.0}, {-124.0, 119.0}, {31.0, -50.0}, {-3.0, -113.0}, {106.0, 21.0}, {52.0, 91.0}, {91.0, 213.0}, {100.0, 129.0}, {-12.0, 46.0}, {-115.0, -82.0}, {261.0, 131.0}, {-131.0, -140.0}, {140.0, -26.0}, {-152.0, -47.0}, {-119.0, -180.0}, {-100.0, -80.0}, {129.0, 152.0}, {140.0, 197.0}, {21.0, 119.0}, {100.0, -77.0}, {5.0, -177.0}, {-17.0, -93.0}, {103.0, 148.0}, {-161.0, -209.0}, {-58.0, -120.0}, {92.0, -149.0}, {36.0, -15.0}, {103.0, 104.0}, {-146.0, 100.0}, {80.0, -13.0}, {-63.0, -30.0}, {61.0, 99.0}, {-91.0, 14.0}, {41.0, 105.0}, {62.0, 5.0}, {-26.0, 80.0}, {158.0, 74.0}, {-143.0, -240.0}, {199.0, 177.0}, {44.0, 214.0}, {122.0, 238.0}, {-7.0, -110.0}, {115.0, -23.0}};

void encrypt(group_ring* H, group_ring* PHI, group_ring* M,Term P,Term q,group_ring*E){

    

    poly_Zw_mul_p(H->a,P,N);
    poly_Zw_mul_p(H->b,P,N);
    poly_Zw_mul_p(H->c,P,N);

    poly_ZwCnC3_mod(H,q,H);

    

    poly_ZwCnC3_mul(H, PHI, T, E);

    poly_ZwCnC3_mod(E,q,E);

    // printf("ph*phi: \n"); 

    // poly_ZwCnC3_print(E);

    // printf("\n-----------------------------------\n");

    poly_ZwCnC3_mod(M,q,M);

    poly_ZwCnC3_add(E,M,E);

    poly_ZwCnC3_mod(E,q,E);

}