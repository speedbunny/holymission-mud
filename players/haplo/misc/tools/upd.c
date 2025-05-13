

/* this file is an include file. You can include it in an object and then
   put in the init the functions add_action("_upd","upd") and 
   add_action("_ld","ld"). With upd you can then update the whole directory
   where you are in and with ld you can load the whole directory.

                          I think that will save you work Whisky :)
                                                                   */

int _upd()
{
    string path;
    string *files;
    object master;
    int i, sz;

    path = "/"+this_player()->query_path()+"/";
    files = get_dir(path+".");

    for (sz = sizeof(files),i=0;i<sz;i++)
    {
        if (master = find_object(path+files[i]))
        {
            write(files[i]+"\n");
            destruct(master);
         }
    }
    write("Ok, "+path+" updated.\n");
    return 1;
}

        
int _ld()
{
    string path;
    string *files;
    int i, sz;

    path = "/"+this_player()->query_path()+"/";
    files = get_dir(path+".");

    for (sz = sizeof(files),i=0;i<sz;i++)
    {
       if (!catch(call_other(path+files[i],"???")))
       {
        write(files[i]+"\n");
       }
    }
    write("Ok, "+path+" loaded.\n");
    return 1;
}



/* this file is an include file. You can include it in an object and then
   put in the init the functions add_action("_upd","upd") and 
   add_action("_ld","ld"). With upd you can then update the whole directory
   where you are in and with ld you can load the whole directory.

                          I think that will save you work Whisky :)
                                                                   */

int _upd()
{
    string path;
    string *files;
    object master;
    int i, sz;

    path = "/"+this_player()->query_path()+"/";
    files = get_dir(path+".");

    for (sz = sizeof(files),i=0;i<sz;i++)
    {
        if (master = find_object(path+files[i]))
        {
            write(files[i]+"\n");
            destruct(master);
         }
    }
    write("Ok, "+path+" updated.\n");
    return 1;
}

        
int _ld()
{
    string path;
    string *files;
    int i, sz;

    path = "/"+this_player()->query_path()+"/";
    files = get_dir(path+".");

    for (sz = sizeof(files),i=0;i<sz;i++)
    {
       if (!catch(call_other(path+files[i],"???")))
       {
        write(files[i]+"\n");
       }
    }
    write("Ok, "+path+" loaded.\n");
    return 1;
}

