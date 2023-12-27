### Repositorio y Ramas

Este proyecto utiliza GitHub o GitLab como repositorio de código fuente. Se han creado las siguientes ramas:

- `master`: Rama principal del proyecto.
- `desarrollo`: Rama para integrar cambios en desarrollo.
- `integranteX` (o `featureX`): Ramas individuales para cada integrante del equipo o características específicas.

Se realiza la integración de cambios mediante merges, siguiendo el flujo `integranteX` (o `featureX`) -> `desarrollo` -> `master`. Además, se sincronizan los cambios utilizando rebase o merge, siguiendo el flujo `master` -> `desarrollo` (y opcionalmente, `desarrollo` -> `integranteX`).

### Pipeline de CI/CD en Jenkins

Se implementa un pipeline de CI/CD en Jenkins con las siguientes etapas y pasos:
## Construcción Automática:
   - Se utiliza la herramienta Maven o Gradle para proyectos Java.

## Análisis Estático de Código Fuente:
   - Se incorpora la herramienta SonarQube para realizar análisis estático del código fuente y mejorar la calidad del mismo.

## Pruebas Unitarias:
   - Se implementan pruebas unitarias utilizando frameworks xUnit, como JUnit para proyectos Java.
**Ejemplo de Pruebas Unitarias**
- *Prueba de Proyección Por Intervalos desde el endpoint /api_gestordepagos/pagos/update*

La prueba utiliza `supertest` para realizar una solicitud PATCH al endpoint `/api_gestordepagos/pagos/update` con un conjunto de datos de prueba. Luego, verifica que la respuesta del servidor tenga un código de estado 200 y un encabezado de tipo de contenido `application/json`.

Además, se espera que la respuesta del servidor coincida con una estructura específica, que se define en las expectativas. En este caso, se espera que la respuesta sea un array que contenga un objeto con propiedades como `fieldCount`, `affectedRows`, `insertId`, entre otras.

#### Notas Importantes:

- La prueba asume que el servidor se puede cerrar adecuadamente después de todas las pruebas utilizando `server.close()` en la función `afterAll()`.

- Ajusta las expectativas según la estructura real de la respuesta que esperas del servidor.

- Asegúrate de que la ruta del endpoint `/api_gestordepagos/pagos/update` y la estructura de datos de prueba sean consistentes con la implementación real del servidor.


## Pruebas Funcionales:
   - Se realizan pruebas funcionales con el framework Selenium o Appium para garantizar el correcto funcionamiento de la aplicación.

Mis disculpas por la confusión. Veo que solo quieres incluir el fragmento de código específico en el README. Aquí está el README con la sección de código que proporcionaste:

**Ejemplo de Pruebas Funcionales**

*- Prueba Funcional de Usuarios*

El archivo `pruebas.py` contiene un conjunto de pruebas funcionales utilizando el framework de testing `pytest` y la biblioteca `selenium` para realizar pruebas automatizadas en una aplicación web. A continuación, se proporciona una descripción de las principales funciones y la estructura del código:

```python
import pytest
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# ... (Clases y métodos anteriores)

class TestFunctionalTests:
    def setup_method(self):
        self.driver = webdriver.Chrome()
        self.driver.get("http://localhost:3000/pagos_mykonos/login")

    def teardown_method(self):
        self.driver.quit()

    def test_login_and_create_customer(self):
        login_page = LoginPage(self.driver)
        login_page.enter_username("IS2@unsa.edu.com")
        login_page.enter_password("CSUNSA")
        login_page.click_login_button()

        customer_page = CustomerPage(self.driver)
        pagos_button = WebDriverWait(self.driver, 10).until(
            EC.element_to_be_clickable((By.XPATH, '//*[@id="root"]/div/header/div/div/div[4]/button[3]'))
        )
        pagos_button.click()

        # Crear usuario
        customer_page.crear_usuario("Andre", "Le", "71837183", "andrea@example.com", "ewpassword", "ewpassword")
        
        # Cambiar contraseña del usuario
        customer_page.change_password("al71837159", "71837159", "71837159")

        # Llama a la función para eliminar al usuario
        # customer_page.eliminar_usuario()

        # Realiza las verificaciones necesarias para asegurarte de que el cliente se haya eliminado correctamente

if __name__ == "__main__":
    pytest.main()
```

En este fragmento, he incluido solo el código relevante para la prueba funcional de usuarios en el README. Puedes ajustar el formato según tus preferencias y agregar más detalles según sea necesario.
## Pruebas de Performance:
   - Se llevan a cabo pruebas de rendimiento utilizando la herramienta JMeter para evaluar el desempeño de la aplicación bajo diferentes condiciones.

## Pruebas de Seguridad:
   - Se ejecutan pruebas de seguridad utilizando la herramienta OWASP ZAP para identificar y corregir posibles vulnerabilidades.

## Gestión de Issues:
   - Se utiliza GitHub Issues, Trello o Jira para la gestión efectiva de problemas y tareas, permitiendo un seguimiento adecuado del progreso del proyecto.

El pipeline de CI/CD se ha implementado de manera integral, abarcando desde la construcción automática hasta la gestión de issues, asegurando un proceso de desarrollo continuo y una entrega continua de la aplicación web.
