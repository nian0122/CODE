"""empty message

Revision ID: 3c63205d23dd
Revises: 750b77b15bcb
Create Date: 2023-10-31 21:32:24.212997

"""
from alembic import op
import sqlalchemy as sa
from sqlalchemy.dialects import mysql

# revision identifiers, used by Alembic.
revision = '3c63205d23dd'
down_revision = '750b77b15bcb'
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.create_table('question',
    sa.Column('id', sa.Integer(), autoincrement=True, nullable=False),
    sa.Column('title', sa.String(length=100), nullable=False),
    sa.Column('content', sa.Text(), nullable=False),
    sa.Column('create_time', sa.DateTime(), nullable=True),
    sa.Column('author_id', sa.Integer(), nullable=True),
    sa.ForeignKeyConstraint(['author_id'], ['user.id'], ),
    sa.PrimaryKeyConstraint('id')
    )
    op.create_table('answer',
    sa.Column('id', sa.Integer(), autoincrement=True, nullable=False),
    sa.Column('content', sa.Text(), nullable=False),
    sa.Column('create_time', sa.DateTime(), nullable=True),
    sa.Column('question_id', sa.Integer(), nullable=True),
    sa.Column('author_id', sa.Integer(), nullable=True),
    sa.ForeignKeyConstraint(['author_id'], ['user.id'], ),
    sa.ForeignKeyConstraint(['question_id'], ['question.id'], ),
    sa.PrimaryKeyConstraint('id')
    )
    with op.batch_alter_table('email_captcha', schema=None) as batch_op:
        batch_op.alter_column('email',
               existing_type=mysql.VARCHAR(length=128),
               type_=sa.String(length=100),
               existing_nullable=False)
        batch_op.alter_column('captcha',
               existing_type=mysql.VARCHAR(length=64),
               type_=sa.String(length=100),
               existing_nullable=False)
        batch_op.drop_index('email')

    with op.batch_alter_table('user', schema=None) as batch_op:
        batch_op.add_column(sa.Column('username', sa.String(length=100), nullable=False))
        batch_op.alter_column('password',
               existing_type=mysql.VARCHAR(length=128),
               type_=sa.String(length=200),
               existing_nullable=False)
        batch_op.alter_column('email',
               existing_type=mysql.VARCHAR(length=128),
               type_=sa.String(length=100),
               existing_nullable=False)
        batch_op.drop_column('Username')

    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    with op.batch_alter_table('user', schema=None) as batch_op:
        batch_op.add_column(sa.Column('Username', mysql.VARCHAR(length=64), nullable=False))
        batch_op.alter_column('email',
               existing_type=sa.String(length=100),
               type_=mysql.VARCHAR(length=128),
               existing_nullable=False)
        batch_op.alter_column('password',
               existing_type=sa.String(length=200),
               type_=mysql.VARCHAR(length=128),
               existing_nullable=False)
        batch_op.drop_column('username')

    with op.batch_alter_table('email_captcha', schema=None) as batch_op:
        batch_op.create_index('email', ['email'], unique=False)
        batch_op.alter_column('captcha',
               existing_type=sa.String(length=100),
               type_=mysql.VARCHAR(length=64),
               existing_nullable=False)
        batch_op.alter_column('email',
               existing_type=sa.String(length=100),
               type_=mysql.VARCHAR(length=128),
               existing_nullable=False)

    op.drop_table('answer')
    op.drop_table('question')
    # ### end Alembic commands ###