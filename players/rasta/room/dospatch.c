get() { return 1; }
drop() { return 1; }
id(str) { return str=="dospatch"; }
long()
{
        write("Commands:\n"+
                "ll <path>     - ls-type command.\n"+
                "quota         - displays your disk usage.\n");
}
 
short() { return "Dospatch"; }
 
reset(arg)
  {
        if(arg) return;
 
}
 
init()
{
        add_action("dir","ll");
        add_action("quota","quota");
}
 
dir(path)
{
        string *dir;
        int i,total_fs,total_ds,total_files,total_dirs;
 
        if(!path) path="/"+this_player()->query_path();
 
        else path=this_player()->evaluate_path(path);
 
        if(path!="/") path+="/";
 
        dir=get_dir(path);
 
        write("Directory of "+path+":\n");
 
        for(i=0;i<sizeof(dir);i++)
        {
                int size,no_pause;
 
                no_pause=20;
 
                size=file_size(path+dir[i]);
 
                if(size==-2)
                {
                        size=dir_size(path+dir[i]+"/");
                        dir[i]+="/";
                        total_dirs++;
                        total_ds+=size;
                }
 
                else
                {
                        total_files++;
                        total_fs+=size;
                }
 
                write(size+"\t"+dir[i]+"\n");
                no_pause--;
                if(!no_pause)
                {
                        input_to("pause");
                        no_pause=20;
                }
 
        }
 
        write(total_files+" files using "+total_fs+" b, "+total_dirs+
                " directories using "+total_ds+" b.\n");
        return 1;
}
 
dir_size(path)
     {
        int total,i;
        string *dir;
 
        dir=get_dir(path);
 
        for(i=0;i<sizeof(dir);i++)
        {
                int size;
 
                size=file_size(path+dir[i]);
 
                if(size==-2) total+=dir_size(path+dir[i]+"/");
                else total+=size;
        }
                return total;
}
 
pause()
{
        return;
}
 
quota(arg)
{
        if(arg) return;
 
        write("You are currently using "+
        dir_size("/players/"+this_player()->query_real_name()+"/")+" bytes.\n");
 
        return 1;
 
}
