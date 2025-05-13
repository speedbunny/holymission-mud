#define	PW_EXPIRY	60
#define	PW_WARN		7

int is_wizard;
int level;
int ftp_user;
static string *wiz_list;
static mixed *wiz_data;

void map_wiz_info(string fname,string ch) {
string name;

    name=(explode(fname,".")[0]);
    restore_object("/p/"+ch+"/"+name);
    if (is_wizard && !ftp_user) {
		write(name+" "+level+"\n");
		wiz_list+=({ name });
		wiz_data+=({ ({ level, "wiz_scan",PW_EXPIRY,PW_WARN,PW_EXPIRY }) });
    }
}

mapping create_all() {
string dir,pldir;
string ch;
int i;

    wiz_list=wiz_data=allocate(0);
    for (i='a';i<='z';i++) {
	ch=to_string(({i}));
        dir="/p/"+ch+"/"+ch+"*.o";
	pldir=master_object()->get_dir(dir);
	map_array(pldir,"map_wiz_info",this_object(),ch);
    }
    return(mkmapping(wiz_list,wiz_data));
}

mapping create_list(string pre) {
    string *pldir,name;
    string dir;
    int i,tmp;

    if (pre=="") return create_all();

    write("scanning \""+pre+"\" ..... \n");
    dir="/p/"+to_string(({pre[0]}))+"/"+pre+"*.o";
    write("dir = "+dir+"\n");
    pldir=master_object()->get_dir("/p/"+to_string(({pre[0]}))+"/"+pre+"*.o");
    if (!pldir) write("no pldir!!!!\n");
    wiz_list=wiz_data=allocate(0);
    for(i=0;i<sizeof(pldir);i++) {
        name=(explode(pldir[i],".")[0]);
        restore_object("p/"+to_string(({pre[0]}))+"/"+name);
        if (is_wizard && !ftp_user) {
            wiz_list+=({ name });
            wiz_data+=({ ({ level,"wiz_scan",PW_EXPIRY,PW_WARN,PW_EXPIRY }) });
        }
    }
    return(mkmapping(wiz_list,wiz_data));
}
