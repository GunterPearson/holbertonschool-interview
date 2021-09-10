#!/usr/bin/python3
"""Count it module"""
import requests
import sys


def count_words(subreddit, word_list, cont={}, next=None, rea={}):
    """count words"""
    headers = {"User-Agent": "nildiert"}
    if next:
        subr = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json?after=' + next, headers=headers)
    else:
        subr = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json', headers=headers)

    if subr.status_code == 404:
        return

    if cont == {}:
        for word in word_list:
            cont[word] = 0
            rea[word] = word_list.count(word)

    subr_dict = subr.json()
    data = subr_dict['data']
    next = data['after']
    subr_posts = data['children']

    for post in subr_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in cont:
                if w.lower() == key.lower():
                    cont[key] += 1
    if next:
        count_words(subreddit, word_list, cont, next, rea)
    else:
        for key, val in rea.items():
            if val > 1:
                cont[key] *= val
        sorted_abc = sorted(cont.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
