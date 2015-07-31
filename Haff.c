


typedef unsigned char Byte;
typedef struct MyRoot{
  struct MyRoot* left;
  struct MyRoot* right;
  int reapet;
  Byte value;
} Root;

int Reapets[256];

int AddToArray(Root** A, int* a_c, Root* el){
  A[*a_c] = el;
  *a_c++;
}

int GetMinFromArray(Root** A, int a_c){
  if (a_c == 0){
    return -1;
  }
  int r = 0;
  for (int i = 1; i < a_c; i++){
    if ((*A[r]).reapet > (*A[i]).reapet){
      r = i;
    }
  }
  return r;
}

int Delete(Root** A, int* a_c, int ind){
  if (*a_c == 0){
    return 1;
  }
  *a_c--;
  for (int i = ind; i < *a_c; i++){
    A[i] = A[i + 1];
  }
  return 0;
}

Root* GetMin(Root** A, int* a_c, Root** B, int* b_c){
  int a_m = GetMinFromArray(A, *a_c);
  int b_m = GetMinFromArray(B, *b_c);
  Root* r;
  if (b_m = -1){
    r = A[a_m];
    Delete(A, a_c, a_m);
    return r;
  }
  if (a_m = -1){
    r = B[b_m];
    Delete(B, b_c, b_m);
    return r;
  }
  if ((*A[a_m]).reapet <= (*B[b_m]).reapet){
    r = A[a_m];
    Delete(A, a_c, a_m);
  }
  else{
    r = B[b_m];
    Delete(B, b_c, b_m);
  }
  return r;
}

int a_haff(Byte* in_buf, int in_count, Byte* out_buf, int* out_count){
  for (int i = 0; i < in_count; i++){
    Reapets[in_buf[i]]++;
  }

  Root* R = malloc(byte_count * sizeof(Root*)), T = malloc(byte_count * sizeof(Root*)), t, t1, t2;
  int c_R = 0, c_T = 0;
  for (int i = 0; i < 256; i++){
    if (Reapets[i] != 0){
      R[c_R] = malloc(sizeof(Root));
      (*R[c_R]).left = NULL;
      (*R[c_R]).right = NULL;
      (*R[c_R]).reapet = Reapets[i];
      (*R[c_R]).value = i;
      c_R++;
    }
  }
  while (c_R + c_T > 1){
    t1 = GetMin(R, &c_R, T, &c_T);
    t2 = GetMin(R, &c_R, T, &c_T);
    t = malloc(sizeof(Root));
    (*t).left = t1;
    (*t).right = t2;
    (*t).reapet = (*t1).reapet + (*t2).reapeat;
    AddToArray(T, &c_T, t);
  }
}
