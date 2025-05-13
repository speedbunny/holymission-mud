inherit "/obj/thing";

reset(int arg)
 {
   ::reset(arg);
   if (!arg)
   {
     set_name("echoer");
     set_short("A magic echoer");
     set_long("This is the fascinating magic echoer.\n"+
              "Type echoinfo for a little help.\n");
   }
 }

void init()
{
  ::init();
  add_action("bold_say",  "bsay");
  add_action("bold_tell", "btell");
  add_action("flash_say", "fsay");
  add_action("flash_tell","ftell");
  add_action("boldf_say", "bfsay");
  add_action("rev_say",   "rsay");
  add_action("revf_say",  "rfsay");
  add_action("und_say",   "usay");
  add_action("undf_say",  "ufsay");
  add_action("boldu_say", "busay");
  add_action("boldr_say", "brsay");
  add_action("boldf_tell","bftell");
  add_action("rev_tell",  "rtell");
  add_action("revf_tell", "rftell");
  add_action("und_tell",  "utell");
  add_action("undf_tell", "uftell");
  add_action("boldu_tell","butell");
  add_action("boldr_tell","brtell");
  add_action("help_echo", "echoinfo");
  
}

status bold_say (string str)
{
  if (str)
  {
  lsay ("says:","[1m" + str + "[0m \n",this_player(),0);
  write("You say: "+"[1m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}

status bold_tell (string all)
{
  
  string who,str;
  object ob;
    
  
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[1m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [1m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("What would you like to tell him?\n");
    }
  }  
  else
  {
    write ("Usage: btell <who> <what>\n"); 
  }
  return 1;
}

status flash_say (string str)
{
  if (str)
  {
  lsay ("says:","[5m" + str + "[0m \n",this_player(),0);
  write("You say: "+"[5m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}
 
status flash_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[5m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [5m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: ftell <who> <what>\n"); 
  }
  return 1;
}


status rev_say (string str)
{
  if (str)
  {
  lsay ("says:","[7m" + str + "[0m \n",this_player(),0);
  write("You say: "+"[7m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}
                      
status rev_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[7m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [7m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: rtell <who> <what>\n"); 
  }
  return 1;
}

status und_say (string str)
{
  if (str)
  {
  lsay ("says:","[4m" + str + "[0m \n",this_player(),0);
  write("You say: "+"[4m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}

status und_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[4m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [4m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: utell <who> <what>\n"); 
  }
  return 1;
}

status boldf_say (string str)
{
  if (str)
  {
  lsay ("says:","[1m"+"[5m"+ str + "[0m \n",this_player(),0);
  write("You say: "+"[1m" + "[5m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}

status boldf_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[1m"+"[5m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [1m"+"[5m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: bftell <who> <what>\n"); 
  }
  return 1;
}

status revf_say (string str)
{
  if (str)
  {
  lsay ("says:","[7m"+"[5m"+ str + "[0m \n",this_player(),0);
  write("You say: "+"[7m" + "[5m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}

status revf_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[7m"+"[5m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [7m"+"[5m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: rftell <who> <what>\n"); 
  }
  return 1;
}

status undf_say (string str)
{
  if (str)
  {
  lsay ("says:","[4m"+"[5m"+ str + "[0m \n",this_player(),0);
  write("You say: "+"[4m" + "[5m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}

status undf_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[4m"+"[5m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [4m"+"[5m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: uftell <who> <what>\n"); 
  }
  return 1;
}

status boldu_say (string str)
{
  if (str)
  {
  lsay ("says:","[1m"+"[4m"+ str + "[0m \n",this_player(),0);
  write("You say: "+"[1m" + "[4m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}

status boldu_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[1m"+"[4m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [1m"+"[4m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: butell <who> <what>\n"); 
  }
  return 1;
}

status boldr_say (string str)
{
  if (str)
  {
  lsay ("says:","[1m"+"[7m"+ str + "[0m \n",this_player(),0);
  write("You say: "+"[1m" + "[7m" + str + "[0m \n");
  }
  else  
  { 
    write ("What would you like to say?\n");
  }
  return 1;
}

status boldr_tell (string all)
{
  
  string who,str;
  object ob;
    
  if (all)
  {
    sscanf (all,"%s %s",who,str);
    if (str)
    {
      ob = find_living(who);
      if (ob)
      {
        tell_object (ob,capitalize(this_player()->query_name())+" tells you: " + "[1m"+"[7m" + str + "[0m \n");
        write("You tell " + ob->query_real_name() + ": [1m"+"[7m" + str + "[0m \n");
      }
      else 
      {
        write ("That person is not part of this reality.\n");      
      }  
    }
    else 
    {  
      write ("Really?\n");
    }
  }  
  else
  {
    write ("Usage: brtell <who> <what>\n"); 
  }
  return 1;
}

status help_echo ()
{
  write ("Help on how to use The Fascinating Magic Echoer by Thorm Co."+"\n"+
        "\n"+
        "bsay   : Bold say"                 +"\n"+
        "btell  : Bold tell"                +"\n"+
        "fsay   : Flashing say"             +"\n"+
        "ftell  : Flashing tell"            +"\n"+
        "bfsay  : Bold&Flashing say"        +"\n"+
        "rsay   : Reverse say"              +"\n"+
        "rfsay  : Reverse&Flashing say"     +"\n"+
        "usay   : Underlined say"           +"\n"+
        "ufsay  : Underlined & Flashing say"+"\n"+
        "busay  : Bold&Underlined say"      +"\n"+
        "brsay  : Bold&Reverse say"         +"\n"+
        "bftell : Bold&Flashing tell"       +"\n"+
        "rtell  : Reverse tell"             +"\n"+
        "rftell : Reverse&Flashing tell"    +"\n"+
        "utell  : Underlined tell"          +"\n"+
        "uftell : Underlined&Flashing tell" +"\n"+
        "butell : Bold&Underlined tell"     +"\n"+
        "brtell : Bold&Reverse tell"        +"\n"+
        "\n"+
        "Please note that the above commands work only on terminals"+"\n"+
        "supporting ANSI terminal codes !"+"\n");
  return 1;
}


int drop (int silently)
{
  if (!silently) write ("The magic echoer falls into pieces...\n");
  destruct (this_object());
  return 1;  
}

