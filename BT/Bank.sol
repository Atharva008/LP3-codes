//SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;

contract Banking{
    mapping(address=>uint) public user_acc;
    mapping(address=>bool) public exist_acc;

    function create_acc() public payable returns (string memory){
        require(exist_acc[msg.sender] == false , "Account Already Exists") ;
        user_acc[msg.sender] = msg.value;
        exist_acc[msg.sender] = true;
        return "Account Created Successfully!";
    }

    function deposite(uint amount) public payable returns (string memory){
        require(exist_acc[msg.sender] == true , "Acount Doesn't Exist");
        require(amount > 0 , "Amount should be Greater than zero!!");
        user_acc[msg.sender] += amount;

        return "Deposit Successful !!";
    }

    function withdraw(uint amount) public payable returns (string memory){
        require(exist_acc[msg.sender] == true , "Acount Doesn't Exist");
        require(amount > 0 , "Amount should be Greater than zero!!");
        require(amount <= user_acc[msg.sender] , "Insufficient Balance");
        user_acc[msg.sender] -= amount;
        return "Withdraw Successful !!";
    }

    function showBalance() public view  returns(uint){
        return user_acc[msg.sender];
    }

    function accExists() public view  returns(bool){
        return exist_acc[msg.sender];
    }




}