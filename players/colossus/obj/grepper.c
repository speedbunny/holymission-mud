#define SIZE 100
int matched;

id(str) { return str=="grepper"; }
short(){ return "Grepper"; }
long(){ write("Usage: grep <regexp> <filename>.\n"); }

get(){ return 1; }
init(){ add_action("grep", "grep"); }
move(dest){ move_object(this_object(), dest); }
grep(str) {
    string exp,file;
    string path,dummy;
    string *files;
    int i;

    if (sscanf(str,"%s %s",exp,file)!=2)
	return 0;
    if(file[0]!="/")
	file=this_player()->query_path()+"/"+file;
    if (sscanf(file,"%s*%s",path,dummy)>=1) {
	write("file mask = "+file+"\n");
	files=get_dir(file);
	if (!files) {
	    write("No such file(s).\n");
	    return 1;
	}
	for (i=0;i<sizeof(files);i++) {
	    grep_it(path+files[i],exp);
	}
	return 1;
    }
    grep_it(file,exp);
    return 1;
}

grep_it(string file,string exp) {
    int current_line;
    string lines;

    current_line=0;          
    matched=0;
    write("File: "+file+"\n");
    while((lines=read_file(file,current_line,SIZE))!=0) {
	grep_string(lines,exp);
	current_line+=SIZE;
    }
    if (current_line==0)
	write("File(s) not found.\n");
    else
	write(matched+" lines matched.\n");
    return 1;
}

void grep_string(string lines,string exp) {
    string *lines_array;
    string *matched_arr;
    int i;

    lines_array=explode(lines,"\n");
    matched_arr=regexp(lines_array,exp);
    if (!matched_arr)
	return;                  
    for (i=0;i<sizeof(matched_arr);i++) {
	write(matched_arr[i]);
	write("\n");
    }
    matched+=sizeof(matched_arr);
}
