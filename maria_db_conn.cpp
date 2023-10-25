#include <iostream>
#include <mysql.h>

using namespace std;

void main()
{
    MYSQL* conn;
    MYSQL* conn_result;
    unsigned int timeout_sec = 1;

    conn = mysql_init(NULL);
    mysql_options(conn, MYSQL_OPT_CONNECT_TIMEOUT, &timeout_sec);
    conn_result = mysql_real_connect(conn, "127.0.0.1", "root", "dnckdals1!", "mysql", 3306, NULL, 0);


    if (NULL == conn_result)
    {
        cout << "DB Connection Fail" << endl;
    }
    else
    {
        cout << "DB Connection Success" << endl;

        char query[1024];
        MYSQL_RES* result;
        MYSQL_ROW row;

        sprintf_s(query, 1024, "SELECT * FROM test");
        //
        // Send Query
        if (mysql_query(conn, query))
        {
            cout << "SELECT Fail" << endl;
        }

        // Get Response
        result = mysql_store_result(conn);

        int fields = mysql_num_fields(result);    // 필드 갯수 구함

        while (row = mysql_fetch_row(result))     // 모든 레코드 탐색
        {
            for (int i = 0; i < fields; i++)    // 각각의 레코드에서 모든 필드 값 출력
            {
                cout << row[i] << "   ";
            }
            cout << endl;
        }

        mysql_free_result(result);
        mysql_close(conn);
    }

    return;
}