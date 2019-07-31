# python3-webapp
======================

### This is a python webapp for learning.
***
#### [效果图](https://github.com/wangwangqin523/algorithm/raw/master/webapp-python/图片1.jpg)
***
#### 理解

***
```python
@get('/manage/blogs')
def manage_blogs(*, page='1'):
    return {
        '__template__': 'manage_blogs.html',
        'page_index': get_page_index(page)
    }
```
====================

#### [路由选择图](https://github.com/wangwangqin523/algorithm/raw/master/webapp-python/1.jpg?raw=true)

#### [整体思路图](https://github.com/wangwangqin523/algorithm/tree/master/webapp-python/2.jpg?raw=true)

作者前端使用uikit和vue




