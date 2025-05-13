/*-------------------------------------------------------------------------*/
/* FILE : mylook.c                                                         */
/*                                                                         */
/* DESC : This contains the look that is called from living.c and          */
/*        pluralizes items in the room.                                    */
/*-------------------------------------------------------------------------*/
#define NUMS\
        ({"","two ","three ","four ","five ","six ","seven ","eight ",\
          "nine ","many "})
#define ENV    environment()
#define CAP    capitalize

string get_plural(int num) {
  return (num < 10 ? NUMS[(num-1)] : NUMS[9]);
}

string plural_word(string word, int num) {
  string tmp, cap_wd, full_wd, *ploder;
  mixed ch, slask;
    
  cap_wd = capitalize(word);

  if(strlen(word) > 2) {
    if(cap_wd[0..1]=="A ")
      word = word[2..<1];
    else if(cap_wd[0..2]=="An ")  
      word = word[3..<1];
  }

  if(num < 2) 
    return word;

  ploder = explode(word," ");

  if(sizeof(ploder) > 1) {
    full_wd = implode(ploder[0..<2]," ");
    full_wd += " ";
    word = CAP(ploder[<1]);
  }
  else {
    full_wd = "";
    word = cap_wd;
  }

  switch(word) {
    case "Tooth": return full_wd + "Teeth";
    case "Foot" : return full_wd + "Feet";
    case "Mouse": return full_wd + "Mice";
    case "Louse": return full_wd + "Lice";
    case "Man"  : return full_wd + "Men";
    case "Woman": return full_wd + "Women";
    case "Child": return full_wd + "Children";
    case "Coin" : return full_wd + "Coins";
    case "coin" : return full_wd + "coins";
    case "Coins": return full_wd + "Coins";
    case "Sheep": return full_wd + "Sheep";
//    case "Key"  : return full_wd + "Keys";
//    case "Boy"  : return full_wd + "Boys";
  }
  if(strlen(word) <= 2) 
    return (full_wd + word); 
  ch = word[<1..<1];
  tmp = word[0..<3];
  slask = word[<2..<2];

/* was this way...but i didn't see the point 
  slask = extract(word, word_len-1, word_len-1);
*/

  switch(ch) {
    case "s": return full_wd + tmp + slask + "ses";
    case "x": return full_wd + tmp + slask + "xes";
    case "h": return full_wd + tmp + slask + "hes";
    case "y": 
      switch(slask) {
        case "a" :
        case "e" :
        case "i" :
        case "o" :
        case "u" : break;
        default  : return full_wd + tmp + slask + "ies";
      }
      break;
    case "e": 
      if(slask == "f")
        return full_wd + tmp + "ves";
  }
  return full_wd + word + "s";
}

varargs int mylook(int brief, object here) {
  string all_live_str, all_others_str, sho, name, info;
  int sz, num, pl;
  object *all, *all_ob, *all_lv, envt;
  mixed *all_live, *all_others;

  if(!(envt = here))
    envt = ENV;

  if(!envt) {
    write("You are in the void and therefore cannot see anything...\n");
    return 1;
  }

  if(!brief)
    call_other(envt, "long");
  else if(brief == 1) 
    write(call_other(envt, "short")+"\n");

  all = all_inventory(envt) - ({ this_player() });

  if(sizeof(all) < 1)
    return 1;

  all_lv = filter_objects(all, "query_hp");
  all_ob = all - all_lv;

  all_live = unique_array(all_lv, "query_name_info");
  all_others = unique_array(all_ob, "query_name");

  sz = sizeof(all_live); 
  all_live_str = "";

  while(sz) {
    sz--;
    pl = sizeof(all_live[sz]);
    sho = call_other(all_live[sz][0], "short");

    if(!sho || !call_other(all_live[sz][0], "query_show_short"))
      name = call_other(all_live[sz][0], "query_name_info");
    else name = sho;

    if(name != "Someone") {
//      info=call_other(all_live[sz][0], "look_info");
      all_live_str += get_plural(pl) + plural_word(name,pl) +
                      (info ? info : "")+", ";
    }
  }

  if((sz=strlen(all_live_str)) > 2) {
    all_live_str = all_live_str[0..sz-3];
    all_live_str = CAP(all_live_str) + ".";
    printf("%-=80s\n", all_live_str);
  } 
  sz = sizeof(all_others); 
  all_others_str = "";

  while(sz) {
    sz--;
    pl = sizeof(all_others[sz]);
    sho = call_other(all_others[sz][0], "short");

    if(sho) {
      if(!call_other(all_others[sz][0], "query_show_short"))
        sho = call_other(all_others[sz][0], "query_name");

      all_others_str += get_plural(pl) + plural_word(sho,pl) + ", ";
      all_ob -= all_others[sz];
    }
  }
  if(sizeof(all_ob)) {
    all_others = unique_array(all_ob, "short");
    sz = sizeof(all_others); 
    while(sz) {
      sz--;
      pl = sizeof(all_others[sz]);
      sho = call_other(all_others[sz][0], "short");

      if(sho) {
        all_others_str += get_plural(pl) + plural_word(sho,pl) + ", ";
      }
    }
  }
  if(strlen(all_others_str) > 2) {
    all_others_str = all_others_str[0..<3];
    all_others_str = CAP(all_others_str) + ".";
    printf("%-=80s\n", all_others_str);
  }
  return 1;
}
