
#!/bin/bash

file="addressbook.txt"

while true
do
    echo ""
    echo "----- ADDRESS BOOK -----"
    echo "1. Create Address Book"
    echo "2. View Address Book"
    echo "3. Insert a Record"
    echo "4. Delete a Record"
    echo "5. Modify a Record"
    echo "6. Exit"

    echo "Enter your choice:"
    read ch

    case $ch in

    1)
        touch $file
        echo "Address Book Created Successfully!"
        ;;

    2)
        echo "----- Address Book Records -----"
        if [ -s $file ]
        then
            cat $file
        else
            echo "Address Book is Empty!"
        fi
        ;;

    3)
        echo "Enter Name:"
        read name
        echo "Enter Phone Number:"
        read phone
        echo "Enter Address:"
        read address

        echo "$name | $phone | $address" >> $file
        echo "Record Inserted Successfully!"
        ;;

    4)
        echo "Enter Name to Delete:"
        read name

        grep -v "^$name |" $file > temp
        mv temp $file

        echo "Record Deleted Successfully!"
        ;;

    5)
        echo "Enter Name to Modify:"
        read name

        grep -v "^$name |" $file > temp
        mv temp $file

        echo "Enter New Name:"
        read newname
        echo "Enter New Phone Number:"
        read newphone
        echo "Enter New Address:"
        read newaddress

        echo "$newname | $newphone | $newaddress" >> $file
        echo "Record Modified Successfully!"
        ;;

    6)
        echo "Exiting Address Book..."
        exit
        ;;

    *)
        echo "Invalid Choice!"
        ;;

    esac
done



1. Give execution permission:
chmod +x addressbook.sh


5. Run the program:
./addressbook.sh
