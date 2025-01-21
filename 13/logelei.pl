%% lösung

losung(A , B, C, D) :-

aussage(A) ,
aussage(B) ,
aussage(C) ,
aussage(D) ,

und(A,B, A_und_B) ,
nicht(C, Nicht_C) ,
und(A_und_B, Nicht_C, A_und_B_und_Nicht_C) ,
nicht(B, Nicht_B) ,
und(A, Nicht_B, A_und_Nicht_B) ,
und(A_und_Nicht_B, C, A_und_Nicht_B_und_C) ,
und(B,C, B_und_C) ,
nicht(A, Nicht_A) ,
und(Nicht_A, B_und_C, Nicht_A_und_B_und_C) ,
oder(A_und_B_und_Nicht_C, A_und_Nicht_B_und_C, Erste_oder_Zweite) ,
oder(Erste_oder_Zweite, Nicht_A_und_B_und_C, wahr) ,

impliziert(Nicht_A, D, wahr) ,

nicht(D, Nicht_D) ,
oder(Nicht_D, Nicht_A, Nicht_D_oder_Nicht_A) ,
impliziert(B, Nicht_D_oder_Nicht_A, wahr) ,

impliziert(C, Nicht_B, wahr) ,

impliziert(A,D,wahr) .

