
#define SAVEFILE "/players/whisky/guild/portals/"

mapping places;
int time;

void reset(int flag)
{
  string *files;
  int i, sz;

     if (flag == 1)
     {
       files = get_dir(SAVEFILE);
       for (sz = sizeof(files), i = 0; i < sz; i++)
       {
            restore_object(files[i]);
            if (time < 1)
                rm(files[i]+".o");
            time--;
            save_object(files[i]);
       }
    }
}


int add_place(string name,string place,string file)
{
    time = 30;

    if (file_size(SAVEFILE+name+".o") == -1)
    {
        places = ([]);
    }
    else 
        restore_object(SAVEFILE+name);
    if (sizeof(m_indices(places)) > 19)
    {
        write("There is a maximum of 20 stored places allowed.\n");
        return 1;
    }
    else if (strlen(place) > 8)
    {
       write("The stringlen of your alias must be < 9.\n");
       return 1;
    }
    places = places + ([place:file]);
    write("Ok, new place stored.\n");
    save_object(SAVEFILE+name);
    return 1;
}

int remove_place(string name,string place)
{
    time = 30;

    restore_object(SAVEFILE+name);

    if (!mappingp(places))
        places = ([]);

    if (member(places,place)==1)
    {
       write("Ok, removed.\n");
       places = m_delete(places,place);
       write(place+"\n");
       save_object(SAVEFILE+"name");
       return 1;
    }
    write("No such place stored.\n");
    return 1;
}
       
int show_places(string name)
{
  string *pla;
  int i, sz;

  restore_object(SAVEFILE+name);

  if (mappingp(places))
      pla = m_indices(places);
  else 
      places = ([]);

  write("Stored places:\n\n");

  for (sz = sizeof(pla), i = 0; i < sz; i++)
       write(pla[i]+"\n");
  save_object(SAVEFILE+name);
  return 1;
}

mixed exist_place(string place,string name)
{ 
    
  restore_object(SAVEFILE+name);

  if (member(places,place)==1)
      return places[place];
   return 0;
} 
