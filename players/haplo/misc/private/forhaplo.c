int compare_str(string str1,string str2) {
  if(str1==str2)
    return 1;
  else
    return 2;
}

string do_compare(string str1,string str2) {
  if(compare_str(str1,str2)==1)
    return "They are the same.\n";
  else if(compare_str(str1,str2)==2)
    return "They are different.\n";
  else
    return "Something went wrong!\n";
}

int compare_fun(string str) {
  string str1,str2;
  if(!str) {
    notify_fail("You must give me 2 words to compare.\n");
    return 0;
  }
  else if(sscanf(str,"%s %s",str1,str2)==2) {
    write(do_compare(str1,str2));
    return 1;
  }
  else {
    write("You must give me 2 words to compare.\n");
    return 1;
  }
}

int compare_fun2(string str) {
  string str1,str2;
  if(!str) {
    notify_fail("You must give me 2 words to compare.\n");
    return 0;
  }
  else if(sscanf(str,"%s %s",str1,str2)==2) {
    if(compare_str(str1,str2)==1)
      write("They are the same.\n");
    else if(compare_str(str1,str2)==2)
      write("They are different.\n");
    else
      write("Something went wrong!\n");
    return 1;
  }
  else {
    write("You must give me 2 words to compare.\n");
    return 1;
  }
}
