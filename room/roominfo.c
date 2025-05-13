#define SCREEN_WIDTH 78

string get_number(int i);
string short_dir(string str);

string get_long_exits(string *dest_dir) {
  string premsg, exits;
  int i, j;
  if(!dest_dir || !sizeof(dest_dir))
    return "    No obvious exits.\n";
  i=1;
  j=sizeof(dest_dir);
  if(j==2)
    premsg="    There is one obvious exit: ";
  else
    premsg=sprintf("    There are %s obvious exits: ", get_number(j/2));
  exits=dest_dir[i];
  for(i=3;i<j;i+=2) {
    if(i==j-1)
      exits+=sprintf(" and %s", dest_dir[i]);
    else
      exits+=sprintf(", %s", dest_dir[i]);
  }
  return sprintf("%s%-=*s\n", premsg, SCREEN_WIDTH-strlen(premsg), exits);
}

string get_number(int i) {
  switch(i) {
    case 0:  return "no";     break;
    case 1:  return "one";    break;
    case 2:  return "two";    break;
    case 3:  return "three";  break;
    case 4:  return "four";   break;
    case 5:  return "five";   break;
    case 6:  return "six";    break;
    case 7:  return "seven";  break;
    case 8:  return "eight";  break;
    case 9:  return "nine";   break;
    default: return "many";
  }
}

string get_short_exits(string *dest_dir) {
if(!dest_dir || !sizeof(dest_dir))
    return "no obvious exits";
  else {
    string msg;
    int i,j;
    j=sizeof(dest_dir);
    msg="";
    for(i=1;i<j;i+=2)
      msg=sprintf("%s%s,", msg, short_dir(dest_dir[i]));
    return msg[0..strlen(msg)-2];
  }
}

string short_dir(string str) {
  switch(str) {
    case "north":
    case "south":
    case "east":
    case "west":
    case "up":
    case "down":      return str[0..0]; break;
    case "northeast":
    case "southeast":
    case "southwest":
    case "northwest": return str[0..0] + str[5..5];
    default:          return str;
  }
}

int query_prevent_shadow() {
  return 1;
}
