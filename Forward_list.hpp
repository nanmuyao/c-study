//
//  Forward_list.hpp
//  练习
//
//  Created by hanzhiqiang on 2017/6/11.
//  Copyright © 2017年 hanzhiqiang. All rights reserved.
//

#ifndef Forward_list_hpp
#define Forward_list_hpp

#include <stdio.h>
#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<string> mList;
    mList.emplace_front("aaa");
    mList.emplace_front("bbb");
    mList.emplace_front("ccc");
    
    for (auto it = mList.begin(); it != mList.end(); it++)
    {
        cout<<*it<<endl;
    }
    
//    for (auto it = mList.before_begin(); it != mList.end(); it++)
//    {
//        cout<<*it<<endl;
//    }
    
//    auto itList = find(mList.begin(), mList.end(), "fff");
//    if (itList != mList.end()) \
//    {
//        mList.emplace_after(itList, "111");
//    }
//    else
//    {
//        mList.insert_after(mList.end(),"222");//c++ primer p 313 向末尾插入数据结果为止  erro099r
//    }
    
    auto prev = mList.before_begin();
    auto curr = mList.begin();
    bool isInsert = false;
    while (curr != mList.end())
    {
        if (*curr == "bbb")
        {
            curr = mList.insert_after(curr, "111");
            isInsert = true;
        }
        prev = curr;
        curr++;
    }
    
    if(!isInsert)
    {
//        curr = mList.insert_after(prev, "222");//向末尾插入数据成功
    }
    
    for (auto it = mList.begin(); it != mList.end(); it++)
    {
        cout<<"插入元素后"<<*it<<endl;
    }
    
    cout<<"fuck"<<endl;
    {
        forward_list<int> flst = {1,2,3,4};
        auto prev = flst.before_begin();
        auto curr = flst.begin();
        
        while (curr != flst.end())
        {
            if ((*curr & 1) == 0)//判断偶数
            {
                cout<<"delete="<<*curr<<endl;
//                error curr
//                1
//                2
//                3
//                4
//                delete=2
//                1
//                2
//                4
//                delete=4

//                right prev
//                delete=2
//                1
//                3
//                4
//                1
//                3
//                4
//                delete=4
//                1
//                3
                curr = flst.erase_after(prev);//删除偶数
            }
            else
            {
                prev = curr;
                curr++;
            }
            auto it = flst.begin();
            while (it != flst.end())
            {
                cout<<*it <<endl;
                it++;
            }
        }
//        auto it = flst.begin();
//        while (it != flst.end())
//        {
//            cout<<*it <<endl;
//            it++;
//        }
    }
    return 0;
}

#endif /* Forward_list_hpp */
