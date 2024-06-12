import java.awt.Desktop;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class SiteOpener {
    private static final Map<String, String> SITES = new HashMap<>();

    static {
        // Mapeie os nomes dos sites para suas URLs correspondentes
        SITES.put("google", "https://www.google.com");
        SITES.put("stackoverflow", "https://stackoverflow.com");
        SITES.put("github", "https://github.com");
        // Adicione mais sites conforme necessário
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite o nome do site que deseja visitar:");
        String siteName = scanner.nextLine().toLowerCase(); // Converta para minúsculas

        if (SITES.containsKey(siteName)) {
            String url = SITES.get(siteName);
            openWebsite(url);
        } else {
            System.out.println("Site não encontrado.");
        }
    }

    private static void openWebsite(String url) {
        if (Desktop.isDesktopSupported()) {
            Desktop desktop = Desktop.getDesktop();
            try {
                desktop.browse(new URI(url));
            } catch (IOException | URISyntaxException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Não foi possível abrir o navegador padrão.");
        }
    }
}
