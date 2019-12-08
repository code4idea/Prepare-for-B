void insertionSort(int list[], int n){
  int iI, mI, nowNum;
  
  // 인덱스 0은 이미 정렬된 것. (시작이므로)
  for(iI = 1; iI < n; iI++){
    nowNum = list[iI];
    
    for(mI=iI-1; mI>=0 && list[mI] > nowNum; mI--){
      list[mI+1] = list[mI];
    }
    
    list[mI+1] = nowNum;
  }
}
