from flask import Blueprint,render_template

bp = Blueprint('pc', __name__,url_prefix="/")

# @bp.route("/")
# def hello():
#     return 'Hello 中国'

@bp.route("/")
def register():
    return render_template("register.html")