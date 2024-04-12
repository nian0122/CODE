from flask import Flask, request, render_template
import os
import subprocess

import QA
import SparkApi
from to_word_helper import stt_api_get_result

app = Flask(__name__)


class SharedData:
    filename = None
    question = None


@app.route('/')
def hello():
    return 'hello!'


@app.route('/record')
def index():
    return render_template('index.html')


@app.route('/save_recording', methods=['POST'])
def save_recording():
    recording = request.data

    # 生成不重复的文件名
    i = 1
    while os.path.exists(f'recording/recording{i}.wav'):
        i += 1
    filename = f'recording/recording{i}.wav'

    # 保存录音文件
    with open(filename, 'wb') as f:
        f.write(recording)

    # 使用ffmpeg将录音文件转换为mp3格式
    subprocess.run(['E:\\ffmpeg\\bin\\ffmpeg', '-i', filename, '-ar', '16000', '-ac', '1', '-ab', '16k',
                    f'recording/recording{i}.mp3'])
    filename = './recording/' + f'recording{i}.mp3'
    SharedData.filename = filename
    # stt_api_get_result('5f39ccd8', 'f6d0d54675341a4dc0404aa640afc3e7', 'ZWUxMjhhM2VkNzk1MzI5N2FhYzliODZk', filename)
    # return redirect(url_for('test_input', filename=filename))
    return "success!"


@app.route("/record/test_input")
def test_input():
    filename = SharedData.filename
    # filename = './recording/recording3.mp3'
    # filename = request.args.get('filename')
    # stt_api_get_result('5f39ccd8', 'f6d0d54675341a4dc0404aa640afc3e7', 'ZWUxMjhhM2VkNzk1MzI5N2FhYzliODZk', filename)
    stt_api_get_result('5f39ccd8', 'f6d0d54675341a4dc0404aa640afc3e7', 'ZWUxMjhhM2VkNzk1MzI5N2FhYzliODZk', filename)
    with open('./static/data.txt', 'r') as f:
        text = f.readlines()
    result = ''.join(text)
    SharedData.question = result  # 储存问题
    return render_template("home.html", result=result)


@app.route("/record/test_input/test_output")
def process_data():
    data = SharedData.question
    question = QA.checklen(QA.getText("user", data))
    SparkApi.answer = ""
    SparkApi.main(QA.appid, QA.api_key, QA.api_secret, QA.Spark_url, QA.domain, question)
    return render_template("home.html", result=SparkApi.get_ans())
    # return SparkApi.get_ans()


if __name__ == '__main__':
    app.run()
