inherit "room/room";

string sname,sartist,splace;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Song Room";
    long_desc="This room contains all the songs that are sung.\n";
    set_light(1);
    smell="It smells different somehow.";
    sname=({"Moving","I'm so lonesome I could cry","Pop song 89",
            "Goodbye cruel world","Piano man","White mountain",
            "My back door","Rock'n'roll suicide","Manic monday",
            "Just like heaven","Will you?","Africa"});
    splace=({"moving","lonesome","popsong",
             "goodbye","piano","mountain",
             "backdoor","suicide","monday",
             "heaven","willyou","africa"});
     sartist=({"Kate Bush","the Cowboy Junkies","REM",
               "Pink Floyd","Billy Joel","Genesis",
               "Melissa Etheridge","David Bowie","Bangles",
               "the Cure","Hazel O'Connor","Rastaman"});
  }
}

query_list() {
int i;

  write("List of possible songs:\n");
  for(i=0; i<sizeof(sname); i=i+1) {
    write(sname[i]+" by "+sartist[i]+".\n");
  }
}

query_song(str) {
int i,name;

  name=0;
  for(i=0; i<sizeof(sname); i=i+1) {
    if(sname[i]==str) {
      name=splace[i];
    }
  }
  return name;
}

