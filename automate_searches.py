import pyautogui as pg
import time
import os
import subprocess

WORDS_FILE = 'words.txt'
INDEX_FILE = 'index.txt'

def save_index(index):
    with open(INDEX_FILE, 'w') as f:
        f.write(str(index))

def load_index(file_path):
    try:
        with open(file_path, 'r') as f:
            index_str = f.read().strip()
            if not index_str:
                return 0  # Default to 0 if the file is empty
            return int(index_str)
    except ValueError:
        print("Error: The file does not contain a valid integer.")
        return 0  # Default to 0 or handle as needed


def load_words(file_path):
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        return f.read().splitlines()


def perform_action(words_list, i):
    app_path = r"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe"
    time.sleep(5)
    subprocess.Popen(app_path)
    time.sleep(5)  # Allow some time for the application to open
    for _ in range(3):
        current_word = words_list[i]
        pg.moveTo(982, 62, duration=0.5)
        pg.click()
        pg.typewrite(current_word, interval=0.2)
        pg.press("enter")
        time.sleep(5)
        i = (i + 1) % len(words_list)
    time.sleep(2)
    pg.moveTo(1890, 17, duration=0.2)
    pg.click()
    return i

if __name__ == "__main__":
    words_list = load_words(WORDS_FILE)
    i = load_index(INDEX_FILE)
    for _ in range(15):
        i = perform_action(words_list, i)
        save_index(i)
        print(f'It has been {_ + 1} iterations')
        time.sleep(10 * 60)  # 10 minutes
