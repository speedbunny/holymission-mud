void spread()
  {
  int num[5];
  int sum;
  int right = 0;

  while(!right)
    {
    for(i = 0; i< 5; i++) 
      {
      num[i] = random(101);
      sum += num[i];
      }
    sum -= 100;
    sum = sum / 5;
    right = 1;
    for(i = 0; i< 5; i++) 
      {
      num[i] -= sum;
      if(num[i] < 5)
        right = 0;
      }
    }
  }

