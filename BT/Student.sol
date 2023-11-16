// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;




contract Student_Management{

    struct student{
        int stud_id;
        string name;
        string dept;
    }

    student[] Students;

    function addStudent(int id , string memory n , string memory d) public{
        Students.push(student(id , n , d));
    }

    function getStudent(int s_id) public view returns (string memory , string memory){
        for(uint i = 0 ; i < Students.length ; i++){
            if(Students[i].stud_id == s_id){
                return (Students[i].name , Students[i].dept);
            }
        }
        return ("Name not found" , "Department not found");
    }

    function delete_stud(int s_id) public{
         for(uint i = 0 ; i < Students.length ; i++){
            if(Students[i].stud_id == s_id){
                delete Students[i];
            }
        }
    }

    function update_stud(int s_id , string memory stu_name) public{
         for(uint i = 0 ; i < Students.length ; i++){
            if(Students[i].stud_id == s_id){
                Students[i].name = stu_name;
            }
        }
    }
}