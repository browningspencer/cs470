//
//  lab05.cpp
//  lab05
//
//  Created by Spencer Browning on 5/25/19.
//  Copyright © 2019 Spencer Browning. All rights reserved.
//

/******************************
 * Homegraph Lab
 *
 * Author: Spencer Browning
 *
 * A homograph is two or more words that are spelled the same
 * but aren't necessarily pronounced the same. Can have different
 * meanings and origins.
 *
 * Program that detects file path homograph attacks. Prompts
 * the user for two filenames and then displays whether those
 * two file names are homographs.
 *
 ******************************/

#include <string>
#include <iostream>


/******************************
 * getFilePath()
 *
 * Takes input and strips "../" and "./"
 ******************************/

std::string getFilePath(std::string file_name);

int main(int argc, const char * argv[]) {
    
    std::string file1;
    std::string file2;
    
    std::string file_path;
    
    std::cout << "Specify the first filename:  ";
    std::cin >> file1;
    
    file_path = getFilePath(file1);
    
    std::cout << "Specify the second filename: ";
    std::cin >> file2;
    
    std::cout << "The paths are "
    << ((file_path == getFilePath(file2)) ? "" : "NOT ")
    << "homographs\n";
    
    
    return 0;
}

std::string getFilePath(std::string file_name)
{
    //    Output
    std::string file_path = "";
    
    //    Number of slashes used in switch statement
    int slashes_num = 0;
    
    // iterates through each character in file_name
    for (int i = 0; i < file_name.length(); i++)
    {
        //    adds '/' before file_path
        if (i == 0 && file_name[i] != '/')
        {
            file_path += "/";
        }
        
        //    catches "./" and "../"
        if (file_name[i] == '.')
        {
            switch (file_name[i + 1])
            {
                    //    current directory "./"
                case '/':
                    i += 1;
                    break;
                    //    parent directory "../"
                case '.':
                    // moves iterator to '/'
                    i += 2;
                    
                    //    if the parent file_path is '/',
                    //    no change and slashes_num is
                    //    decreased
                    if (--slashes_num <= 1)
                    {
                        file_path = "/";
                        break;
                    }
                    
                    //    if parent isn't '/'
                    else
                    {
                        int temp = 0;
                        std::string temp_path = "";
                        int j = 0;
                        
                        //    copy file_path unitl slashes_num
                        //    is decreased enough
                        while (temp != slashes_num)
                        {
                            if (file_path[j] == '/')
                            {
                                temp++;
                            }
                            temp_path += file_path[j++];
                        }
                        
                        file_path = temp_path;
                        break;
                    }
            }
            
            continue;
        }
        
        //    add character to file_path
        if (file_name[i] == '/')
        {
            slashes_num++;
        }
        file_path += file_name[i];
    }
    
    return file_path;
}
