from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

# Função para conectar ao banco de dados SQLite
def connect_db():
    return sqlite3.connect('birthdays.db')

# Rota para GET e POST
@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        # Obter dados do formulário
        name = request.form.get('name')
        month = request.form.get('month')
        day = request.form.get('day')

        # Inserir nova linha na tabela birthdays
        conn = connect_db()
        c = conn.cursor()
        c.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", (name, month, day))
        conn.commit()
        conn.close()

        # Redirecionar para a página inicial
        return redirect('/')
    else:
        # Consultar o banco de dados para todos os aniversários
        conn = connect_db()
        c = conn.cursor()
        c.execute("SELECT * FROM birthdays")
        birthdays = [dict(row) for row in c.fetchall()]
        conn.close()

        # Renderizar o template index.html com os dados dos aniversários
        return render_template('index.html', birthdays=birthdays)

if __name__ == '__main__':
    app.run(debug=True)
